// Problem: Jump Game II
// LC: https://leetcode.com/problems/jump-game-ii/
//
// Given nums[i] = max jump length from index i, return the minimum number of
// jumps to reach the last index. You are guaranteed to reach the last index.
//
// Input Format:
//   Line 1: n
//   Line 2: n space-separated non-negative integers
//
// Output Format:
//   Single integer: minimum jumps (0 if n == 1)
//
// Example:
//   Input:  5 / 2 3 1 1 4
//   Output: 2
//
// Constraints:
//   1 <= n <= 10^4
//   0 <= nums[i] <= 1000
//   It is always possible to reach the last index

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Greedy BFS-style jumps using current reach and next reach
}

void run_tests() {
    vector<TestCase> tests = {
        {"5\n2 3 1 1 4\n",          "2"},
        {"5\n2 3 0 1 4\n",          "2"},
        {"1\n1\n",                  "0"},
        {"4\n1 1 1 1\n",            "3"},
        {"5\n1 2 1 1 1\n",          "3"},
        {"7\n7 0 0 0 0 0 0\n",      "1"},
        {"3\n1 2 3\n",              "2"},
        {"5\n2 1 1 1 1\n",          "3"},
        {"5\n5 4 3 2 1\n",          "1"},
        {"5\n1 1 1 1 1\n",          "4"},
        {"5\n3 3 1 1 4\n",          "2"},
        {"6\n1 2 1 1 1 1\n",        "4"},
        {"6\n2 3 1 1 1 1\n",        "3"},
        {"4\n2 1 1 1\n",            "2"},
        {"3\n2 1 0\n",              "1"},
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
