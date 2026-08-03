// Problem: Subarray Sum Equals K
//
// Given an array of integers nums and an integer k, return the total number
// of continuous subarrays whose sum equals k.
//
// Input Format:
//   First line:  n k
//   Second line: n space-separated integers
//
// Output Format:
//   A single integer: the count of subarrays with sum k
//
// Example:
//   Input:  3 2 / 1 1 1
//   Output: 2
//   (subarrays: [1,1] at indices 0-1 and 1-2)
//
// Constraints:
//   1 <= n <= 2*10^4
//   -1000 <= nums[i] <= 1000
//   -10^7 <= k <= 10^7

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Use prefix sum + hashmap
}

void run_tests() {
    vector<TestCase> tests = {
        {"3 2\n1 1 1\n",         "2"},
        {"1 1\n1\n",             "1"},
        {"1 0\n0\n",             "1"},
        {"4 -1\n-1 -1 1 1\n",    "3"},
        {"3 3\n1 2 3\n",         "2"},
        {"5 0\n0 0 0 0 0\n",     "15"},
        {"4 5\n1 2 3 4\n",       "1"},
        {"4 -2\n-1 1 -1 1\n",    "4"},
        {"6 3\n1 2 1 2 1 2\n",    "4"},
        {"3 100\n1 2 3\n",       "0"},
        {"5 7\n3 4 7 2 -3\n",    "2"},
        {"1 -1\n-1\n",           "1"},
        {"2 0\n0 0\n",           "3"},
        {"5 1\n1 1 1 1 1\n",     "4"},
        {"4 4\n1 1 1 1\n",       "3"},
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
