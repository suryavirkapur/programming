#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using std::cin, std::cout, std::string, std::vector;
using std::istringstream, std::ostringstream;

static constexpr auto GREEN = "\033[1;32m";
static constexpr auto RED   = "\033[1;31m";
static constexpr auto RESET = "\033[0m";

struct ListNode {
    int val;
    ListNode* next{nullptr};
    ListNode(int x) : val(x) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void solve() {
    int n, m;
    cin >> n;
    ListNode dummy1(0), *tail1 = &dummy1;
    std::vector<std::unique_ptr<ListNode>> pool;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        auto node = std::make_unique<ListNode>(v);
        tail1->next = node.get();
        tail1 = tail1->next;
        pool.push_back(std::move(node));
    }
    cin >> m;
    ListNode dummy2(0), *tail2 = &dummy2;
    for (int i = 0; i < m; ++i) {
        int v; cin >> v;
        auto node = std::make_unique<ListNode>(v);
        tail2->next = node.get();
        tail2 = tail2->next;
        pool.push_back(std::move(node));
    }
    ListNode* merged = mergeTwoLists(dummy1.next, dummy2.next);
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
        {"3\n1 2 4\n3\n1 3 4\n",   "1 1 2 3 4 4\n"},
        {"0\n\n0\n\n",              "\n"},
        {"0\n\n1\n5\n",             "5\n"},
        {"3\n1 2 3\n0\n\n",         "1 2 3\n"},
        {"2\n-10 10\n2\n0 5\n",    "-10 0 5 10\n"},
        {"4\n1 3 5 7\n4\n2 4 6 8\n", "1 2 3 4 5 6 7 8\n"},
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
