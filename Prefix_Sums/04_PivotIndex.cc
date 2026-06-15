// Problem: Equilibrium Index / Pivot Index
//
// Given an array of integers, find the smallest index i such that the sum of
// elements to the left of i equals the sum of elements to the right of i.
// If no such index exists, output -1.
//
// Input Format:
//   First line:  n
//   Second line: n space-separated integers
//
// Output Format:
//   The pivot index, or -1
//
// Example:
//   Input:  6 / 1 7 3 6 5 6
//   Output: 3
//   (left sum = 1+7+3 = 11, right sum = 5+6 = 11)
//
// Constraints:
//   1 <= n <= 10^5
//   -10^4 <= nums[i] <= 10^4

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Use prefix sum + total
}

void run_tests() {
    vector<TestCase> tests = {
        {"6\n1 7 3 6 5 6\n",      "3"},
        {"3\n1 2 3\n",            "-1"},
        {"1\n0\n",                "0"},
        {"4\n2 1 -1 0\n",         "0"},
        {"5\n0 0 0 0 0\n",        "0"},
        {"2\n1 1\n",              "-1"},
        {"4\n-1 1 -1 1\n",        "-1"},
        {"7\n1 -1 1 -1 1 -1 1\n", "-1"},
        {"5\n10 5 -3 3 2\n",      "2"},
        {"3\n2 3 2\n",            "1"},
        {"6\n0 0 3 0 0 0\n",      "0"},
        {"2\n-1 1\n",             "0"},
        {"4\n1 2 3 6\n",          "3"},
        {"5\n-2 -2 -2 -2 -2\n",   "-1"},
        {"8\n1 2 3 4 5 6 7 28\n",  "7"},
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
