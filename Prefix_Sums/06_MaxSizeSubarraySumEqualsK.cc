// Problem: Maximum Size Subarray Sum Equals K
//
// Given an array nums and a target k, return the maximum length of a
// subarray that sums to k. If there isn't one, return 0.
//
// Input Format:
//   First line:  n k
//   Second line: n space-separated integers
//
// Output Format:
//   Maximum length of subarray with sum k
//
// Example:
//   Input:  3 3 / 1 -1 5
//   Output: 4  (Note: example below uses 4 -1 2 with k=3 -> answer 4? Let's restate)
//   Input:  4 3 / 1 -1 2 -1
//   Output: 4
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
    // TODO: Use prefix sum + hashmap (earliest index)
}

void run_tests() {
    vector<TestCase> tests = {
        {"4 3\n1 -1 2 -1\n",       "4"},
        {"1 1\n1\n",               "1"},
        {"1 -1\n-1\n",             "1"},
        {"3 0\n0 0 0\n",           "3"},
        {"5 5\n1 2 3 4 5\n",       "1"},
        {"5 15\n1 2 3 4 5\n",      "5"},
        {"5 1\n1 1 1 1 1\n",       "1"},
        {"6 3\n1 2 3 -3 1 2\n",     "6"},
        {"4 0\n-1 1 -1 1\n",       "4"},
        {"5 100\n1 2 3 4 5\n",     "0"},
        {"3 5\n1 1 3\n",           "2"},
        {"5 -3\n-1 -1 1 1 -1\n",   "4"},
        {"4 7\n3 4 7 2\n",         "3"},
        {"5 9\n1 2 3 4 5\n",       "3"},
        {"3 6\n2 2 2\n",           "3"},
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
