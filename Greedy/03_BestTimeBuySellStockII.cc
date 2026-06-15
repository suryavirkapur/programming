// Problem: Best Time to Buy and Sell Stock II
// LC: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//
// Given daily stock prices, you may buy and sell multiple times (but hold at most
// one share). Maximize total profit by capturing every upward price move.
//
// Input Format:
//   Line 1: n
//   Line 2: n space-separated prices
//
// Output Format:
//   Single integer: maximum profit
//
// Example:
//   Input:  6 / 7 1 5 3 6 4
//   Output: 7
//
// Constraints:
//   1 <= n <= 3*10^4
//   0 <= prices[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Sum all positive day-over-day price differences
}

void run_tests() {
    vector<TestCase> tests = {
        {"6\n7 1 5 3 6 4\n",            "7"},
        {"5\n1 2 3 4 5\n",              "4"},
        {"5\n5 4 3 2 1\n",              "0"},
        {"1\n1\n",                      "0"},
        {"3\n2 2 2\n",                  "0"},
        {"2\n1 2\n",                    "1"},
        {"4\n1 5 1 5\n",                "8"},
        {"5\n2 1 2 0 1\n",              "2"},
        {"9\n1 2 3 2 3 0 -1 4 5\n",     "9"},
        {"3\n3 3 3\n",                  "0"},
        {"4\n1 2 1 2\n",                "2"},
        {"6\n1 3 2 4 3 5\n",            "6"},
        {"2\n5 1\n",                    "0"},
        {"7\n2 4 1 5 3 6 2\n",          "9"},
        {"4\n10 10 10 10\n",            "0"},
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
