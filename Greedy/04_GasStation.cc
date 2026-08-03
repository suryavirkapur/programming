// Problem: Gas Station
// LC: https://leetcode.com/problems/gas-station/
//
// There are n gas stations in a circle. gas[i] is fuel available at station i,
// cost[i] is fuel needed to reach the next station. Return the starting station
// index if you can complete the circuit once, otherwise -1. Assume exactly one
// solution exists when feasible.
//
// Input Format:
//   Line 1: n
//   Line 2: n space-separated gas amounts
//   Line 3: n space-separated travel costs
//
// Output Format:
//   Single integer: starting index (0-indexed) or -1
//
// Example:
//   Input:  5 / 1 2 3 4 5 / 3 4 5 1 2
//   Output: 3
//
// Constraints:
//   n == gas.length == cost.length
//   1 <= n <= 10^5
//   0 <= gas[i], cost[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Track total surplus and reset start when running tank drops below 0
}

void run_tests() {
    vector<TestCase> tests = {
        {"5\n1 2 3 4 5\n3 4 5 1 2\n",       "3"},
        {"3\n2 3 4\n3 4 3\n",               "-1"},
        {"5\n5 1 2 3 4\n4 4 1 5 1\n",       "4"},
        {"1\n5\n4\n",                       "0"},
        {"1\n3\n5\n",                       "-1"},
        {"3\n1 1 1\n1 1 1\n",               "0"},
        {"3\n3 1 1\n1 2 2\n",               "0"},
        {"3\n1 2 3\n2 3 1\n",               "2"},
        {"3\n2 2 2\n1 1 3\n",               "0"},
        {"6\n4 5 2 6 5 7\n3 2 7 3 2 4\n",   "3"},
        {"5\n6 1 4 3 5\n3 8 2 4 1\n",       "2"},
        {"2\n1 2\n2 1\n",                   "1"},
        {"3\n3 1 2\n1 2 2\n",               "0"},
        {"4\n1 2 3 4\n4 3 2 1\n",           "2"},
        {"2\n1 1\n2 2\n",                   "-1"},
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
