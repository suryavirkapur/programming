#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::string;
using std::istringstream, std::ostringstream;

static constexpr auto GREEN = "\033[1;32m";
static constexpr auto RED   = "\033[1;31m";
static constexpr auto RESET = "\033[0m";

struct ListNode {
    int val;
    ListNode* next{nullptr};
    ListNode(int x) : val(x) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; ++i) fast = fast->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* toDel = slow->next;
    slow->next = slow->next->next;
    delete toDel;
    return dummy.next;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    ListNode* res = removeNthFromEnd(dummy.next, k);
    const ListNode* cur = res;
    while (cur) {
        cout << cur->val;
        cur = cur->next;
        if (cur) cout << " ";
    }
    cout << "\n";
    while (res) {
        ListNode* nxt = res->next;
        delete res;
        res = nxt;
    }
}

static void trim_right(std::string& s) {
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

void run_tests() {
    struct TestCase { string input; string expected; };
    std::vector<TestCase> tests = {
        {"5 2\n1 2 3 4 5\n",        "1 2 3 5\n"},
        {"2 1\n1 2\n",               "1\n"},
        {"1 1\n42\n",                "\n"},
        {"5 5\n1 2 3 4 5\n",        "2 3 4 5\n"},
        {"5 1\n10 20 30 40 50\n",   "10 20 30 40\n"},
        {"3 2\n7 8 9\n",             "7 9\n"},
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
