// Problem: Lemonade Change
// LC: https://leetcode.com/problems/lemonade-change/
//
// Customers pay $5, $10, or $20 for a $5 lemonade. Provide correct change using
// $5 and $10 bills you hold. Return whether every customer can be served.
//
// Input Format:
//   Line 1: n  (number of customers)
//   Line 2: n space-separated bill denominations (5, 10, or 20)
//
// Output Format:
//   "true" or "false"
//
// Example:
//   Input:  5 / 5 5 5 10 10
//   Output: true
//
// Constraints:
//   1 <= n <= 10^5
//   bills[i] is 5, 10, or 20

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Track $5 and $10 bill counts; greedy change making
}

void run_tests() {
    vector<TestCase> tests = {
        {"4\n5 5 5 10\n",               "true"},
        {"3\n5 5 10\n",                 "true"},
        {"2\n10 10\n",                  "false"},
        {"1\n5\n",                      "true"},
        {"1\n10\n",                     "false"},
        {"1\n20\n",                     "false"},
        {"5\n5 5 10 10 20\n",           "false"},
        {"5\n5 5 10 10 10\n",           "false"},
        {"3\n5 10 20\n",                "false"},
        {"10\n5 5 5 5 5 5 5 5 5 5\n",   "true"},
        {"4\n5 5 10 20\n",              "true"},
        {"6\n5 5 5 10 10 10\n",         "true"},
        {"3\n5 5 20\n",                 "false"},
        {"8\n5 10 5 10 5 10 5 20\n",    "true"},
        {"5\n5 10 5 10 20\n",           "false"},
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
