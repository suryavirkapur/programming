#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::istringstream, std::ostringstream;
using std::string, std::vector;

static constexpr auto GREEN = "\033[32m";
static constexpr auto RED   = "\033[31m";
static constexpr auto RESET = "\033[0m";

void genSubsets(int i, const vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
    if (i == static_cast<int>(nums.size())) {
        ans.push_back(cur);
        return;
    }
    genSubsets(i + 1, nums, cur, ans);
    cur.push_back(nums[static_cast<size_t>(i)]);
    genSubsets(i + 1, nums, cur, ans);
    cur.pop_back();
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    vector<vector<int>> ans;
    vector<int> cur;
    genSubsets(0, nums, cur, ans);

    std::sort(ans.begin(), ans.end(),
        [](const auto& a, const auto& b) {
            if (a.size() != b.size()) return a.size() < b.size();
            return a < b;
        });

    for (size_t i = 0; i < ans.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << (j == ans[i].size() - 1 ? "" : " ");
        cout << "]";
        if (i < ans.size() - 1) cout << "\n";
    }
}

struct TestCase {
    string input;
    string expected;
};

static void trim_right(std::string& s) {
    while (!s.empty() && std::isspace(s.back()))
        s.pop_back();
}

void run_tests() {
    vector<TestCase> tests = {
        {"1 1", "[]\n[1]"},
        {"2 1 2", "[]\n[1]\n[2]\n[1 2]"},
        {"0", "[]"},
        {"3 1 2 3", "[]\n[1]\n[2]\n[3]\n[1 2]\n[1 3]\n[2 3]\n[1 2 3]"},
        {"1 5", "[]\n[5]"},
        {"2 3 4", "[]\n[3]\n[4]\n[3 4]"}    };

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        istringstream ss_in(tests[i].input);
        ostringstream ss_out;

        auto* cin_buf = cin.rdbuf(ss_in.rdbuf());
        auto* cout_buf = cout.rdbuf(ss_out.rdbuf());

        try {
            solve();
        } catch (...) {
            cout.rdbuf(cout_buf);
            cin.rdbuf(cin_buf);
            cout << "Runtime Error in Test " << i << endl;
            continue;
        }

        cin.rdbuf(cin_buf);
        cout.rdbuf(cout_buf);

        string actual = ss_out.str();
        trim_right(actual);
        string expected = tests[i].expected;
        trim_right(expected);

        if (actual == expected) {
            cout << GREEN << "[PASS] Test " << i << RESET << endl;
            ++passed;
        } else {
            cout << RED << "[FAIL] Test " << i << RESET << endl;
            cout << "  Input:    " << tests[i].input << endl;
            cout << "  Expected: " << expected << endl;
            cout << "  Actual:   " << actual << endl;
        }
    }
    cout << "Passed " << passed << "/" << tests.size() << " tests." << endl;
}

int main() { run_tests(); }
