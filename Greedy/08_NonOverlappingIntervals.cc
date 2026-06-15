// Problem: Non-overlapping Intervals
// LC: https://leetcode.com/problems/non-overlapping-intervals/
//
// Given intervals [start, end], return the minimum number of intervals to remove
// so the rest are pairwise non-overlapping.
//
// Input Format:
//   Line 1: n
//   Next n lines: start end (space-separated)
//
// Output Format:
//   Single integer: minimum removals
//
// Example:
//   Input:  4 / 1 2 / 2 3 / 3 4 / 1 3
//   Output: 1
//
// Constraints:
//   1 <= n <= 10^5
//   intervals[i].length == 2
//   -5*10^4 <= start_i < end_i <= 5*10^4

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Sort by end time; greedy keep earliest-ending non-overlapping intervals
}

void run_tests() {
    vector<TestCase> tests = {
        {"4\n1 2\n2 3\n3 4\n1 3\n",         "1"},
        {"3\n1 2\n1 2\n1 2\n",              "2"},
        {"2\n1 2\n2 3\n",                   "0"},
        {"2\n1 3\n2 4\n",                   "1"},
        {"1\n1 2\n",                        "0"},
        {"4\n1 2\n2 3\n3 4\n4 5\n",         "0"},
        {"3\n1 10\n11 22\n2 3\n",           "1"},
        {"4\n0 1\n1 2\n2 3\n3 4\n",         "0"},
        {"3\n1 2\n2 3\n1 3\n",              "1"},
        {"3\n-1 0\n0 1\n-2 -1\n",           "0"},
        {"4\n1 100\n11 22\n2 3\n5 6\n",     "1"},
        {"5\n1 2\n1 3\n2 3\n3 4\n4 5\n",    "1"},
        {"2\n1 10\n2 3\n",                  "1"},
        {"6\n1 2\n2 3\n3 4\n1 4\n5 6\n4 5\n", "1"},
        {"3\n10 11\n1 2\n2 3\n",            "0"},
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
