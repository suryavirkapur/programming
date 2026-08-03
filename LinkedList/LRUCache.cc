#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cin, std::cout, std::string, std::vector;
using std::istringstream, std::ostringstream;
using std::list, std::pair, std::unordered_map;

class LRUCache {
    std::size_t cap_;
    list<pair<int, int>> items_;
    unordered_map<int, decltype(items_)::iterator> lookup_;
public:
    LRUCache(int capacity) : cap_(static_cast<std::size_t>(capacity)) {}

    int get(int key) {
        if (!lookup_.count(key)) return -1;
        int val = lookup_[key]->second;
        items_.erase(lookup_[key]);
        items_.push_front({key, val});
        lookup_[key] = items_.begin();
        return val;
    }

    void put(int key, int value) {
        if (lookup_.count(key)) {
            items_.erase(lookup_[key]);
        } else if (items_.size() >= cap_) {
            int staleKey = items_.back().first;
            items_.pop_back();
            lookup_.erase(staleKey);
        }
        items_.push_front({key, value});
        lookup_[key] = items_.begin();
    }
};

static constexpr auto GREEN = "\033[1;32m";
static constexpr auto RED   = "\033[1;31m";
static constexpr auto RESET = "\033[0m";

void solve() {
    int cap;
    cin >> cap;
    LRUCache cache(cap);
    string cmd;
    while (cin >> cmd) {
        if (cmd == "put") {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
        } else if (cmd == "get") {
            int k;
            cin >> k;
            cout << cache.get(k) << "\n";
        }
    }
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"2\nput 1 1\nput 2 2\nget 1\nput 3 3\nget 2\nput 4 4\nget 1\nget 3\nget 4\n",
         "1\n-1\n-1\n3\n4\n"},
        {"1\nput 2 1\nget 2\nput 3 2\nget 2\nget 3\n",
         "1\n-1\n2\n"},
        {"2\nget 2\nput 2 6\nget 1\nput 1 5\nput 1 2\nget 1\nget 2\n",
         "-1\n-1\n2\n6\n"},
        {"3\nput 1 10\nput 2 20\nput 3 30\nput 4 40\nget 4\nget 1\nget 2\nget 3\n",
         "40\n-1\n20\n30\n"},
        {"2\nput 2 1\nput 1 1\nput 2 3\nput 4 1\nget 1\nget 2\n",
         "-1\n3\n"},
        {"4\nput 1 1\nput 2 2\nput 3 3\nget 1\nget 2\nget 3\nput 4 4\nput 5 5\nget 1\nget 2\n",
         "1\n2\n3\n-1\n2\n"},
    };
    for (size_t i = 0; i < tests.size(); ++i) {
        istringstream iss(tests[i].input);
        ostringstream oss;
        auto* orig_cin  = cin.rdbuf(iss.rdbuf());
        auto* orig_cout = cout.rdbuf(oss.rdbuf());
        solve();
        cin.rdbuf(orig_cin);
        cout.rdbuf(orig_cout);
        string result = oss.str();
        while (!result.empty() && (result.back() == '\n' || result.back() == '\r'))
            result.pop_back();
        string expected = tests[i].expected;
        while (!expected.empty() && (expected.back() == '\n' || expected.back() == '\r'))
            expected.pop_back();
        if (result == expected)
            cout << "[PASS] Test " << (i + 1) << " - " << GREEN << "OK" << RESET << "\n";
        else {
            cout << "[FAIL] Test " << (i + 1) << " - " << RED << "FAILED" << RESET << "\n";
            cout << "  Expected: '" << expected << "'\n";
            cout << "  Actual:   '" << result   << "'\n";
        }
    }
}

int main() { run_tests(); }
