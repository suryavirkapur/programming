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

void solve() {
    int n;
    cin >> n;
    ListNode dummy(0);
    ListNode* tail = &dummy;
    std::vector<std::unique_ptr<ListNode>> pool;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        auto node = std::make_unique<ListNode>(v);
        tail->next = node.get();
        tail = tail->next;
        pool.push_back(std::move(node));
    }
    ListNode *slow = dummy.next, *fast = dummy.next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) cout << slow->val << "\n";
}

static void trim_right(std::string& s) {
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"5\n1 2 3 4 5\n",       "3\n"},
        {"6\n1 2 3 4 5 6\n",     "4\n"},
        {"1\n42\n",               "42\n"},
        {"2\n1 2\n",              "2\n"},
        {"4\n10 20 30 40\n",     "30\n"},
        {"7\n5 10 15 20 25 30 35\n", "20\n"},
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
