#include <iostream>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cin, std::cout, std::string, std::vector;
using std::istringstream, std::ostringstream;
using std::priority_queue;

static constexpr auto GREEN = "\033[1;32m";
static constexpr auto RED   = "\033[1;31m";
static constexpr auto RESET = "\033[0m";

struct ListNode {
    int val;
    ListNode* next{nullptr};
    ListNode(int x) : val(x) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto* head : lists)
        if (head) pq.push(head);
    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}

void solve() {
    int K;
    cin >> K;
    vector<ListNode*> lists(K, nullptr);
    std::vector<std::unique_ptr<ListNode>> pool;
    for (int i = 0; i < K; ++i) {
        int n;
        cin >> n;
        ListNode dummy(0), *tail = &dummy;
        for (int j = 0; j < n; ++j) {
            int v; cin >> v;
            auto node = std::make_unique<ListNode>(v);
            tail->next = node.get();
            tail = tail->next;
            pool.push_back(std::move(node));
        }
        lists[i] = dummy.next;
    }
    ListNode* merged = mergeKLists(lists);
    const ListNode* cur = merged;
    while (cur) {
        cout << cur->val;
        cur = cur->next;
        if (cur) cout << " ";
    }
    cout << "\n";
}

static void trim_right(std::string& s) {
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"3\n3\n1 4 5\n3\n1 3 4\n2\n2 6\n",  "1 1 2 3 4 4 5 6\n"},
        {"0\n",                                 "\n"},
        {"2\n3\n1 2 3\n0\n\n",                  "1 2 3\n"},
        {"1\n1\n42\n",                           "42\n"},
        {"4\n2\n-5 -3\n1\n-10\n2\n0 1\n2\n-4 2\n", "-10 -5 -4 -3 0 1 2\n"},
        {"3\n0\n\n0\n\n1\n5\n",                  "5\n"},
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
        trim_right(result);
        string expected = tests[i].expected;
        trim_right(expected);
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
