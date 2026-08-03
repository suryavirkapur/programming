// Problem: Number of Ways to Split Array
//
// Given an integer array nums, return the number of ways to split it into
// two non-empty parts (prefix and suffix) such that the sum of the prefix
// is greater than or equal to the sum of the suffix.
//
// Input Format:
//   First line:  n
//   Second line: n space-separated integers
//
// Output Format:
//   Number of valid split points
//
// Example:
//   Input:  5 / 10 4 -8 7 2
//   Output: 2
//   (splits at index 2 and 3; prefix sums 14, 6; suffixes -1, 2)
//
// Constraints:
//   2 <= n <= 10^5
//   -10^5 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Use prefix sum and total sum
}

void run_tests() {
    vector<TestCase> tests = {
        {"5\n10 4 -8 7 2\n",       "2"},
        {"3\n2 3 1\n",             "1"},
        {"2\n1 1\n",               "0"},
        {"2\n2 1\n",               "1"},
        {"4\n0 0 0 0\n",           "3"},
        {"4\n-1 -1 -1 -1\n",       "0"},
        {"3\n5 5 5\n",             "2"},
        {"3\n-5 5 5\n",            "0"},
        {"6\n1 1 1 1 1 1\n",       "3"},
        {"5\n100 -50 -50 0 0\n",   "2"},
        {"2\n-5 10\n",             "0"},
        {"4\n3 3 3 3\n",           "3"},
        {"3\n10 -5 5\n",           "1"},
        {"7\n1 2 3 4 3 2 1\n",     "3"},
        {"3\n-1 0 1\n",            "1"},
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
