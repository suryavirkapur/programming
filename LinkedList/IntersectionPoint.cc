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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

void solve() {
    int n, m, skipA, skipB;
    cin >> n >> m >> skipA >> skipB;

    vector<int> valsA(n), valsB(m);
    for (int i = 0; i < n; ++i) cin >> valsA[i];
    for (int i = 0; i < m; ++i) cin >> valsB[i];

    std::vector<std::unique_ptr<ListNode>> pool;
    for (int i = 0; i < n; ++i) pool.push_back(std::make_unique<ListNode>(valsA[i]));
    for (int i = 0; i < n - 1; ++i) pool[static_cast<size_t>(i)]->next = pool[static_cast<size_t>(i) + 1].get();

    ListNode dummyB(0), *tailB = &dummyB;
    for (int i = 0; i < m; ++i) {
        if (skipA >= 0 && skipB >= 0 && i >= skipB) {
            int aIdx = skipA + (i - skipB);
            if (aIdx < n) tailB->next = pool[static_cast<size_t>(aIdx)].get();
        } else {
            auto node = std::make_unique<ListNode>(valsB[i]);
            tailB->next = node.get();
            pool.push_back(std::move(node));
        }
        tailB = tailB->next;
    }

    ListNode* headA = (n > 0) ? pool[0].get() : nullptr;
    ListNode* headB = dummyB.next;
    ListNode* inter = getIntersectionNode(headA, headB);

    if (inter) cout << inter->val << "\n";
    else       cout << "null\n";
}

static void trim_right(std::string& s) {
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"5 6 2 3\n4 1 8 4 5\n5 6 1 8 4 5\n", "8\n"},
        {"0 0 -1 -1\n\n",                       "null\n"},
        {"3 2 1 1\n1 2 3\n4 2 3\n",             "2\n"},
        {"2 3 -1 -1\n1 2\n3 4 5\n",              "null\n"},
        {"1 1 0 0\n42\n42\n",                    "42\n"},
        {"3 2 -1 -1\n1 2 3\n4 5\n",              "null\n"},
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
