// Problem: Jump Game
// LC: https://leetcode.com/problems/jump-game/
//
// Given nums[i] = max jump length from index i, determine if you can reach
// the last index starting from index 0.
//
// Input Format:
//   Line 1: n
//   Line 2: n space-separated non-negative integers
//
// Output Format:
//   "true" or "false"
//
// Example:
//   Input:  5 / 2 3 1 1 4
//   Output: true
//
// Constraints:
//   1 <= n <= 10^4
//   0 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Track farthest reachable index in one pass
}

void run_tests() {
    vector<TestCase> tests = {
        {"5\n2 3 1 1 4\n",      "true"},
        {"5\n3 2 1 0 4\n",      "false"},
        {"1\n0\n",              "true"},
        {"1\n1\n",              "true"},
        {"4\n1 0 1 0\n",        "false"},
        {"3\n2 0 0\n",          "true"},
        {"4\n1 1 1 1\n",        "true"},
        {"2\n0 1\n",            "false"},
        {"3\n3 0 0\n",          "true"},
        {"3\n1 2 3\n",          "true"},
        {"3\n1 0 2\n",          "false"},
        {"3\n2 1 0\n",          "true"},
        {"6\n5 0 0 0 0 0\n",    "true"},
        {"4\n1 1 0 1\n",        "false"},
        {"3\n1 0 0\n",                  "false"},
    };

    for (int i = 0; i < (int)tests.size(); ++i) {
        stringstream ss(tests[i].input);
        streambuf* old_in = cin.rdbuf(ss.rdbuf());
        stringstream out;
        streambuf* old_out = cout.rdbuf(out.rdbuf());

        solve();

        cout.rdbuf(old_out);
        cin.rdbuf(old_in);

        string actual = out.str();
        while (!actual.empty() && (actual.back() == '\n' || actual.back() == ' '))
            actual.pop_back();

        string expected = tests[i].expected;
        while (!expected.empty() && (expected.back() == '\n' || expected.back() == ' '))
            expected.pop_back();

        if (actual == expected) {
            cout << "\033[32m[PASS]\033[0m Test " << (i + 1) << endl;
        } else {
            cout << "\033[31m[FAIL]\033[0m Test " << (i + 1)
                 << "\n  Expected: " << expected
                 << "\n  Actual:   " << actual << endl;
        }
    }
}

int main() {
    run_tests();
    return 0;
}
