// Problem: Assign Cookies
// LC: https://leetcode.com/problems/assign-cookies/
//
// Each child i has a greed factor g[i] (minimum cookie size they will accept).
// Each cookie j has size s[j]. Assign one cookie to each child at most; a child
// is content if cookie size >= greed. Maximize the number of content children.
//
// Input Format:
//   Line 1: m n  (number of children, number of cookies)
//   Line 2: m space-separated greed factors
//   Line 3: n space-separated cookie sizes
//
// Output Format:
//   Single integer: maximum number of content children
//
// Example:
//   Input:  2 3 / 1 2 / 1 2 3
//   Output: 2
//
// Constraints:
//   1 <= m, n <= 3*10^4
//   1 <= g[i], s[j] <= 2^31 - 1

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Sort greed and cookie sizes; two-pointer greedy match
}

void run_tests() {
    vector<TestCase> tests = {
        {"2 3\n1 2\n1 2 3\n",           "2"},
        {"2 3\n1 2\n3 4 5\n",           "2"},
        {"1 1\n1\n1\n",                 "1"},
        {"1 1\n2\n1\n",                 "0"},
        {"4 5\n1 1 2 3\n1 1 2 2 3\n",   "4"},
        {"3 2\n1 2 3\n1 1\n",           "1"},
        {"2 2\n10 9\n5 6\n",            "0"},
        {"2 2\n5 5\n6 7\n",             "2"},
        {"3 3\n1 3 5\n2 4 6\n",         "3"},
        {"3 3\n1 3 5\n2 2 2\n",         "1"},
        {"3 5\n2 2 2\n1 1 1 1 1\n",     "0"},
        {"5 5\n1 2 3 4 5\n1 2 3 4 5\n", "5"},
        {"2 1\n1 5\n10\n",              "1"},
        {"2 3\n10 20\n5 15 25\n",       "2"},
        {"3 4\n3 3 3\n3 3 3 3\n",       "3"},
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
