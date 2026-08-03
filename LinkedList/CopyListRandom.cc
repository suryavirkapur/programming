#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cin, std::cout, std::string, std::vector;
using std::istringstream, std::ostringstream;

static constexpr auto GREEN = "\033[1;32m";
static constexpr auto RED   = "\033[1;31m";
static constexpr auto RESET = "\033[0m";

struct Node {
    int val;
    Node* next{nullptr};
    Node* random{nullptr};
    Node(int x) : val(x) {}
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node* cur = head;
    while (cur) {
        Node* copy = new Node(cur->val);
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while (cur) {
        if (cur->random) cur->next->random = cur->random->next;
        cur = cur->next->next;
    }
    Node dummy(0), *copyTail = &dummy;
    cur = head;
    while (cur) {
        copyTail->next = cur->next;
        copyTail = copyTail->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return dummy.next;
}

void solve() {
    int n;
    cin >> n;
    if (n == 0) { cout << "0\n"; return; }
    vector<std::pair<int, int>> data(n);
    for (int i = 0; i < n; ++i) cin >> data[i].first >> data[i].second;
    std::vector<std::unique_ptr<Node>> pool;
    for (int i = 0; i < n; ++i) pool.push_back(std::make_unique<Node>(data[i].first));
    for (int i = 0; i < n - 1; ++i) pool[static_cast<size_t>(i)]->next = pool[static_cast<size_t>(i) + 1].get();
    for (int i = 0; i < n; ++i)
        if (data[static_cast<size_t>(i)].second >= 0 && data[static_cast<size_t>(i)].second < n)
            pool[static_cast<size_t>(i)]->random = pool[static_cast<size_t>(data[static_cast<size_t>(i)].second)].get();
    Node* copied = copyRandomList(pool[0].get());
    std::unordered_map<Node*, int> idxMap;
    Node* cur = copied;
    int idx = 0;
    while (cur) { idxMap[cur] = idx++; cur = cur->next; }
    cout << n << "\n";
    cur = copied;
    while (cur) {
        int randIdx = (cur->random && idxMap.count(cur->random)) ? idxMap[cur->random] : -1;
        cout << cur->val << " " << randIdx << "\n";
        cur = cur->next;
    }
    while (copied) { Node* nxt = copied->next; delete copied; copied = nxt; }
}

static void trim_right(std::string& s) {
    while (!s.empty() && (s.back() == '\n' || s.back() == '\r'))
        s.pop_back();
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"5\n7 -1\n13 0\n11 4\n10 2\n1 0\n",
         "5\n7 -1\n13 0\n11 4\n10 2\n1 0\n"},
        {"0\n",
         "0\n"},
        {"2\n1 1\n2 0\n",
         "2\n1 1\n2 0\n"},
        {"3\n3 -1\n3 0\n3 -1\n",
         "3\n3 -1\n3 0\n3 -1\n"},
        {"1\n42 -1\n",
         "1\n42 -1\n"},
        {"4\n1 1\n2 2\n3 3\n4 -1\n",
         "4\n1 1\n2 2\n3 3\n4 -1\n"},
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
