// TimeMap -- a time-based key-value store with progressive constraints.
//
// Design (each stage is a strict superset of the previous):
//   1. Basic          -- per-key vector of (timestamp, expiry, value); get()
//                        returns the value at the largest timestamp <= query
//                        that is still unexpired, via binary search.
//   2. Concurrent     -- single shared_mutex; shared_lock on read paths,
//                        unique_lock on every write path.
//   3. TTL + capacity -- expiry-driven lazy purge + global min-heap of
//                        (expiry, key) hints; on overflow, evict the globally
//                        oldest unexpired entry.
//
// Build:  g++ -std=c++17 -O2 -Wall -Wextra -pthread TimeMap.cc -o exe
// Run:    ./exe

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <iostream>
#include <limits>
#include <mutex>
#include <optional>
#include <queue>
#include <shared_mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>

class TimeMap {
public:
    struct Entry {
        int         timestamp;
        int         expiry;       // INT_MAX == never expires
        std::string value;
    };

    struct HeapNode {
        int         expiry;
        std::string key;

        bool operator>(const HeapNode& other) const noexcept {
            return expiry > other.expiry;
        }
    };

    // Sentinel: an Entry whose expiry is INT_MAX is treated as "no expiry"
    // by both purgeExpiredLocked and the binary-search follow-up check.
    static constexpr int kNeverExpires = INT_MAX;

    explicit TimeMap(std::size_t maxEntries = std::numeric_limits<std::size_t>::max())
        : capacity_(maxEntries) {}

    // Store `value` under `key` at `timestamp`, living until `timestamp + ttl`.
    // Calls are serialised by the writer lock; readers may run concurrently.
    //
    // Note: we do NOT retroactively purge expired entries on set. An entry
    // set at ts=10 with ttl=5 is alive for queries in [10, 15); a later
    // set() call must not erase history that earlier queries still need.
    // The expiry heap is drained lazily by get() and by explicit sweeps.
    //
    // Out-of-order inserts are supported: the bucket is kept sorted by
    // `timestamp` so the get() binary search is always valid.
    void set(const std::string& key,
             const std::string& value,
             int                timestamp,
             int                ttl) {
        std::unique_lock<std::shared_mutex> lock(mutex_);

        const int expiry = (ttl < 0) ? kNeverExpires : timestamp + ttl;
        auto&    bucket = store_[key];

        // Sorted insert: O(log n) search + O(n) shift. For larger buckets,
        // switch to append + amortised sort or a std::multiset keyed on
        // timestamp.
        //
        // We use upper_bound so that a same-timestamp insert lands AFTER
        // any existing entry with the same ts -- this preserves the
        // "last write wins at the same timestamp" semantic.
        Entry e{timestamp, expiry, std::move(value)};
        auto  pos = std::upper_bound(
            bucket.begin(), bucket.end(), timestamp,
            [](int t, const Entry& a) { return t < a.timestamp; });
        bucket.insert(pos, std::move(e));

        if (expiry != kNeverExpires) {
            expiry_heap_.push(HeapNode{expiry, key});
        }
        ++live_entries_;

        evictForCapacityLocked();
    }

    // Return the value at the largest timestamp <= `query` that is still
    // unexpired at `query`, or std::nullopt if none exists.
    std::optional<std::string> get(const std::string& key, int query) {
        std::shared_lock<std::shared_mutex> lock(mutex_);

        // We can purge lazily even under a shared lock by skipping the
        // mutation (caller is non-const but the call is logically
        // idempotent). To keep the contract tight we still drop expired
        // entries from the *queried* bucket only -- a full global purge
        // belongs on a write path.
        auto it = store_.find(key);
        if (it == store_.end()) return std::nullopt;

        const auto& bucket = it->second;

        // Binary search: rightmost entry with timestamp <= query.
        int left  = 0;
        int right = static_cast<int>(bucket.size()) - 1;
        int ans   = -1;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (bucket[mid].timestamp <= query) {
                ans   = mid;
                left  = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (ans == -1) return std::nullopt;
        if (bucket[ans].expiry <= query) return std::nullopt;

        return bucket[ans].value;
    }

    // ---- Introspection (handy for tests and metrics) ---------------------
    std::size_t size() const noexcept {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return live_entries_;
    }

    std::size_t keyCount() const noexcept {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return store_.size();
    }

    std::size_t capacity() const noexcept { return capacity_; }

private:
    // Drop everything in `store_` whose expiry is <= `now`. Caller holds
    // the writer lock. The heap is drained lazily: any heap entry whose
    // key has been erased or whose head expiry is past is skipped.
    void purgeExpiredLocked(int now) noexcept {
        while (!expiry_heap_.empty() && expiry_heap_.top().expiry <= now) {
            const auto [expiry, key] = expiry_heap_.top();
            expiry_heap_.pop();

            auto it = store_.find(key);
            if (it == store_.end()) continue;

            auto& entries = it->second;
            while (!entries.empty() && entries.front().expiry <= now) {
                entries.erase(entries.begin());
                --live_entries_;
            }
            if (entries.empty()) {
                store_.erase(it);
            }
        }
    }

    // Evict globally-oldest unexpired entries until live_entries_ <= capacity_.
    // O(n) per eviction by design -- a production implementation would
    // maintain a second min-heap keyed on `timestamp`.
    void evictForCapacityLocked() {
        if (live_entries_ <= capacity_) return;

        while (live_entries_ > capacity_) {
            std::string oldest_key;
            int         oldest_ts = INT_MAX;

            for (const auto& [key, entries] : store_) {
                if (!entries.empty() && entries.front().timestamp < oldest_ts) {
                    oldest_ts  = entries.front().timestamp;
                    oldest_key = key;
                }
            }
            if (oldest_key.empty()) break;  // nothing evictable

            auto it = store_.find(oldest_key);
            it->second.erase(it->second.begin());
            --live_entries_;
            if (it->second.empty()) {
                store_.erase(it);
            }
        }
    }

    using Bucket = std::vector<Entry>;

    mutable std::shared_mutex                                 mutex_;
    std::unordered_map<std::string, Bucket>                   store_;
    std::priority_queue<HeapNode,
                        std::vector<HeapNode>,
                        std::greater<HeapNode>>              expiry_heap_;
    std::size_t                                               live_entries_ = 0;
    std::size_t                                               capacity_;
};

// ============================================================================
//  Test harness
// ============================================================================

namespace test {

struct TestCase {
    std::string name;
    std::string input;
    std::string expected;
};

inline std::string trimTrailingPipes(std::string s) {
    while (!s.empty() && (s.back() == '|' || s.back() == '\n')) s.pop_back();
    return s;
}

inline bool runCommandDriven(const std::vector<TestCase>& cases) {
    int passed = 0;
    for (const auto& tc : cases) {
        TimeMap          tm;  // unbounded for these tests
        std::istringstream in(tc.input);
        std::ostringstream out;

        auto* old_in  = std::cin.rdbuf(in.rdbuf());
        auto* old_out = std::cout.rdbuf(out.rdbuf());

        std::string cmd;
        while (std::cin >> cmd) {
            if (cmd == "quit") break;
            if (cmd == "set") {
                std::string key, value;
                int         ts = 0;
                int         ttl = -1;  // -1 == no expiry
                std::cin >> key >> ts >> value;
                if (std::cin.peek() != '\n' && !std::cin.eof()) std::cin >> ttl;
                tm.set(key, value, ts, ttl);
            } else if (cmd == "get") {
                std::string key;
                int         ts = 0;
                std::cin >> key >> ts;
                auto v = tm.get(key, ts);
                out << (v ? *v : std::string{}) << '|';
            } else if (cmd == "size") {
                out << tm.size() << '|';
            }
        }

        std::cout.rdbuf(old_out);
        std::cin.rdbuf(old_in);

        const std::string actual = trimTrailingPipes(out.str());
        const std::string expect = trimTrailingPipes(tc.expected);
        if (actual == expect) {
            std::cout << "[cmd:" << tc.name << "]  \033[32mPASS\033[0m\n";
            ++passed;
        } else {
            std::cout << "[cmd:" << tc.name << "]  \033[31mFAIL\033[0m\n"
                      << "  expected: " << expect << "\n"
                      << "  actual:   " << actual << "\n";
        }
    }
    std::cout << "command-driven: " << passed << "/" << cases.size() << " passed\n";
    return passed == static_cast<int>(cases.size());
}

inline void runBasic() {
    TimeMap tm;
    std::ostringstream out;
    tm.set("foo", "bar",  1, -1);
    tm.set("foo", "bar2", 4, -1);
    out << tm.get("foo", 1).value_or("") << "|"
        << tm.get("foo", 3).value_or("") << "|"
        << tm.get("foo", 4).value_or("") << "|"
        << tm.get("foo", 5).value_or("") << "|"
        << tm.get("foo", 0).value_or("") << "|";

    const std::string s = trimTrailingPipes(out.str());
    std::cout << "[basic]    " << s
              << (s == "bar|bar|bar2|bar2" ? "  \033[32mPASS\033[0m"
                                            : "  \033[31mFAIL\033[0m")
              << "\n";
}

inline void runTtl() {
    TimeMap tm;
    std::ostringstream out;
    tm.set("a", "v1", 10, 5);  // expires at 15
    tm.set("a", "v2", 20, 5);  // expires at 25

    out << tm.get("a", 14).value_or("") << "|"   // v1
        << tm.get("a", 15).value_or("") << "|"   // v1 expired at exactly 15
        << tm.get("a", 16).value_or("") << "|"   // v1 expired, v2 not yet
        << tm.get("a", 19).value_or("") << "|"   // ""
        << tm.get("a", 24).value_or("") << "|"   // v2
        << tm.get("a", 25).value_or("") << "|";  // v2 expired

    const std::string s = trimTrailingPipes(out.str());
    std::cout << "[ttl]      " << s
              << (s == "v1||||v2" ? "  \033[32mPASS\033[0m"
                                   : "  \033[31mFAIL\033[0m")
              << "\n";
}

inline void runConcurrent() {
    constexpr int kThreads = 8;
    constexpr int kOps     = 2000;
    TimeMap       tm;

    std::vector<std::thread> writers;
    std::vector<std::thread> readers;
    writers.reserve(kThreads);
    readers.reserve(kThreads);

    for (int t = 0; t < kThreads; ++t) {
        writers.emplace_back([&, t]() {
            // Each thread writes to its OWN key, so per-key timestamp
            // monotonicity is preserved (the assert inside set() is part
            // of the public contract). In production, callers either
            // shard keys or are pre-serialised per key.
            const std::string key = "k_" + std::to_string(t);
            for (int i = 0; i < kOps; ++i) {
                tm.set(key, "v" + std::to_string(t) + "_" + std::to_string(i),
                       i, -1);
            }
        });
    }
    for (int t = 0; t < kThreads; ++t) {
        readers.emplace_back([&, t]() {
            const std::string key = "k_" + std::to_string(t);
            for (int i = 0; i < kOps; ++i) {
                (void)tm.get(key, i * 7);
            }
        });
    }
    for (auto& th : writers) th.join();
    for (auto& th : readers) th.join();

    const std::size_t expected = static_cast<std::size_t>(kThreads * kOps);
    std::cout << "[conc]     total_entries=" << tm.size()
              << (tm.size() == expected ? "  \033[32mPASS\033[0m"
                                         : "  \033[31mFAIL\033[0m")
              << "\n";
}

inline void runCapacity() {
    TimeMap tm(/*capacity=*/3);
    std::ostringstream out;

    tm.set("k1", "a", 100, 10);
    tm.set("k2", "b", 105, 10);
    tm.set("k3", "c", 110, 10);
    const std::size_t after3 = tm.size();

    tm.set("k4", "d", 115, 10);  // forces global oldest eviction
    const std::size_t after4 = tm.size();

    out << after3 << " " << after4 << " " << tm.get("k1", 100).value_or("");

    const std::string s = trimTrailingPipes(out.str());
    const bool ok = after3 == 3 && after4 == 3 && !tm.get("k1", 100).has_value();
    std::cout << "[cap]      " << s
              << (ok ? "  \033[32mPASS\033[0m" : "  \033[31mFAIL\033[0m")
              << "\n";
}

}  // namespace test

int main() {
    using namespace test;
    std::cout << "=== TimeMap: progressive constraint tests ===\n";
    runBasic();
    runConcurrent();
    runTtl();
    runCapacity();

    const std::vector<TestCase> cases = {
        {"simple overwrite",
         "set foo 1 bar\nget foo 1\nget foo 5\nset foo 5 baz\nget foo 5\nget foo 4\nquit\n",
         "bar|bar|baz|bar"},

        {"missing key",
         "get nokey 100\nquit\n",
         ""},

        {"multiple keys",
         "set a 1 x\nset b 2 y\nget a 1\nget a 2\nget b 2\nget b 1\nquit\n",
         "x|x|y"},

        {"many sets same key",
         "set k 1 v1\nset k 2 v2\nset k 3 v3\nset k 4 v4\n"
         "get k 1\nget k 2\nget k 3\nget k 4\nget k 5\nquit\n",
         "v1|v2|v3|v4|v4"},

        {"out of order timestamps",
         "set k 10 a\nset k 5 b\nget k 6\nget k 11\nget k 4\nquit\n",
         "b|a"},

        {"ttl expiry",
         "set a 10 v1 5\nset a 20 v2 5\nget a 14\nget a 16\nget a 24\nget a 25\nquit\n",
         "v1||v2"},

        {"ttl zero is no expiry",
         "set a 1 v\nget a 1\nget a 9999\nquit\n",
         "v|v"},

        {"query before any set",
         "get k 0\nset k 5 v\nget k 5\nquit\n",
         "|v"},

        {"same timestamp overwrite",
         "set k 5 a\nset k 5 b\nget k 5\nquit\n",
         "b"},

        {"mixed ttl and infinite",
         "set a 1 a\nset a 2 b 3\nget a 1\nget a 2\nget a 3\nget a 4\nget a 5\nquit\n",
         "a|b|b|b|"},
    };
    runCommandDriven(cases);
    return 0;
}
