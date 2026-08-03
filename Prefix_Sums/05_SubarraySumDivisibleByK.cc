// Problem: Subarray Sums Divisible by K
//
// Given an integer array nums and an integer k, return the number of
// non-empty subarrays whose sum is divisible by k.
//
// Input Format:
//   First line:  n k
//   Second line: n space-separated integers
//
// Output Format:
//   Number of subarrays with sum divisible by k
//
// Example:
//   Input:  6 5 / 4 5 0 -2 -3 1
//   Output: 7
//
// Constraints:
//   1 <= n <= 3*10^4
//   -10^4 <= nums[i] <= 10^4
//   2 <= k <= 10^4

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Use prefix sum modulo + hashmap
}

void run_tests() {
    vector<TestCase> tests = {
        {"6 5\n4 5 0 -2 -3 1\n",  "7"},
        {"1 2\n1\n",              "0"},
        {"1 1\n1\n",              "1"},
        {"3 3\n3 6 9\n",          "6"},
        {"4 2\n1 1 1 1\n",        "4"},
        {"5 5\n5 5 5 5 5\n",      "15"},
        {"3 4\n1 2 3\n",          "1"},
        {"6 2\n1 -1 1 -1 1 -1\n", "12"},
        {"4 7\n7 7 7 7\n",        "10"},
        {"2 10\n5 5\n",           "3"},
        {"5 3\n0 0 0 0 0\n",      "15"},
        {"4 5\n1 2 3 4\n",        "1"},
        {"3 6\n2 4 6\n",          "6"},
        {"5 1\n1 2 3 4 5\n",      "15"},
        {"4 4\n-1 -1 -1 -1\n",    "10"},
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
