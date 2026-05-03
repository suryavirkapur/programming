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

static int listLength(ListNode* head) {
    int len = 0;
    while (head) { ++len; head = head->next; }
    return len;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;
    int len = listLength(head);
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevGroupEnd = &dummy;
    while (len >= k) {
        ListNode* groupStart = prevGroupEnd->next;
        ListNode* prev = nullptr;
        ListNode* curr = groupStart;
        for (int i = 0; i < k; ++i) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        prevGroupEnd->next = prev;
        groupStart->next = curr;
        prevGroupEnd = groupStart;
        len -= k;
    }
    return dummy.next;
}

void solve() {
    int n, k;
    cin >> n >> k;
    ListNode dummy(0), *tail = &dummy;
    std::vector<std::unique_ptr<ListNode>> pool;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        auto node = std::make_unique<ListNode>(v);
        tail->next = node.get();
        tail = tail->next;
        pool.push_back(std::move(node));
    }
    ListNode* res = reverseKGroup(dummy.next, k);
    const ListNode* cur = res;
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
        {"5 2\n1 2 3 4 5\n",            "2 1 4 3 5\n"},
        {"5 3\n1 2 3 4 5\n",            "3 2 1 4 5\n"},
        {"4 2\n1 2 3 4\n",              "2 1 4 3\n"},
        {"1 1\n1\n",                     "1\n"},
        {"7 3\n1 2 3 4 5 6 7\n",        "3 2 1 6 5 4 7\n"},
        {"8 3\n1 2 3 4 5 6 7 8\n",      "3 2 1 6 5 4 7 8\n"},
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
