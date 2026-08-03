// Problem: Product of Array Except Self
//
// Given an integer array nums, return an array answer such that answer[i]
// is equal to the product of all the elements of nums except nums[i].
// Solve in O(n) time WITHOUT using the division operator.
//
// Input Format:
//   First line:  n
//   Second line: n space-separated integers
//
// Output Format:
//   n space-separated integers
//
// Example:
//   Input:  4 / 1 2 3 4
//   Output: 24 12 8 6
//
// Constraints:
//   2 <= n <= 10^5
//   -30 <= nums[i] <= 30
//   The product of any prefix or suffix fits in 32-bit int.

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Use prefix and suffix product arrays
}

void run_tests() {
    vector<TestCase> tests = {
        {"4\n1 2 3 4\n",            "24 12 8 6"},
        {"2\n1 2\n",                "2 1"},
        {"3\n-1 1 0\n",             "0 0 -1"},
        {"3\n0 4 0\n",              "0 0 0"},
        {"3\n1 1 1\n",              "1 1 1"},
        {"5\n2 3 4 5 6\n",          "360 240 180 144 120"},
        {"4\n-1 -2 -3 -4\n",        "-24 -12 -8 -6"},
        {"2\n-1 2\n",               "2 -1"},
        {"3\n2 0 3\n",              "0 6 0"},
        {"6\n1 2 3 4 5 6\n",        "720 360 240 180 144 120"},
        {"3\n10 10 10\n",           "100 100 100"},
        {"4\n-1 -1 -1 -1\n",        "-1 -1 -1 -1"},
        {"2\n0 0\n",                "0 0"},
        {"5\n1 2 0 3 4\n",          "0 0 24 0 0"},
        {"3\n3 5 7\n",              "35 21 15"},
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
