// Problem: Running Sum of 1D Array
//
// Given an array of n integers, compute the running sum (prefix sum) where
// runningSum[i] = sum(nums[0] + nums[1] + ... + nums[i]).
//
// Input Format:
//   First line: integer n
//   Second line: n space-separated integers
//
// Output Format:
//   n space-separated integers representing the running sum
//
// Example:
//   Input:  5 / 1 2 3 4 5
//   Output: 1 3 6 10 15
//
// Constraints:
//   1 <= n <= 10^5
//   -10^4 <= nums[i] <= 10^4

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    size_t n; cin >> n;
    vector<int> nums(n);
    for (size_t i= 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> res(n);
    res[0] = nums[0];
    for (size_t i = 1; i < n; i++) {
        res[i] = res[i-1] + nums[i];
    }
    for (size_t i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void run_tests() {
    vector<TestCase> tests = {
        {"5\n1 2 3 4 5\n",         "1 3 6 10 15"},
        {"4\n3 1 4 1\n",           "3 4 8 9"},
        {"1\n7\n",                 "7"},
        {"3\n-1 -2 -3\n",          "-1 -3 -6"},
        {"6\n0 0 0 0 0 0\n",       "0 0 0 0 0 0"},
        {"5\n10 -5 3 -2 7\n",      "10 5 8 6 13"},
        {"2\n-100 50\n",           "-100 -50"},
        {"8\n1 1 1 1 1 1 1 1\n",   "1 2 3 4 5 6 7 8"},
        {"4\n-1 1 -1 1\n",         "-1 0 -1 0"},
        {"3\n1000 2000 3000\n",    "1000 3000 6000"},
        {"5\n5 4 3 2 1\n",         "5 9 12 14 15"},
        {"2\n-1 -1\n",             "-1 -2"},
        {"7\n2 -2 2 -2 2 -2 2\n",  "2 0 2 0 2 0 2"},
        {"4\n10 10 10 10\n",       "10 20 30 40"},
        {"6\n1 -1 1 -1 1 -1\n",    "1 0 1 0 1 0"},
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
