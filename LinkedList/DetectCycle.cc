#include <iostream>
#include <memory>
#include <sstream>
#include <string>
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

bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void solve() {
    int n, pos;
    cin >> n >> pos;
    std::vector<std::unique_ptr<ListNode>> pool;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        auto node = std::make_unique<ListNode>(v);
        if (i > 0) pool[i - 1]->next = node.get();
        pool.push_back(std::move(node));
    }
    if (pos >= 0 && pos < n && !pool.empty())
        pool.back()->next = pool[static_cast<size_t>(pos)].get();
    ListNode* head = pool.empty() ? nullptr : pool[0].get();
    cout << (hasCycle(head) ? "true" : "false") << "\n";
}

static void trim_right(std::string& s) {
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"5 2\n3 2 0 -4\n",     "true\n"},
        {"1 -1\n1\n",            "false\n"},
        {"2 -1\n1 2\n",          "false\n"},
        {"3 0\n1 2 3\n",         "true\n"},
        {"0 -1\n",               "false\n"},
        {"4 3\n7 8 9 10\n",      "true\n"},
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
