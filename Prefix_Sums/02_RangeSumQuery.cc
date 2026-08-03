// Problem: Range Sum Query - Immutable
//
// Given an integer array nums, answer multiple queries of the form:
//   sumRange(left, right) = sum(nums[left..right]) inclusive
// Preprocess using a prefix sum array so each query is O(1).
//
// Input Format:
//   First line:  n
//   Second line: n space-separated integers
//   Third line:  q (number of queries)
//   Next q lines: left right
//
// Output Format:
//   q lines, each the sum of the range
//
// Example:
//   Input:
//     5
//     -2 0 3 -5 2
//     3
//     0 2
//     2 5
//     0 4
//   Output:
//     1
//     0
//     -2
//   (Wait: indices are 0-based but bounded by n-1. Use 0-based indices.)
//
// Constraints:
//   1 <= n <= 10^5
//   -10^3 <= nums[i] <= 10^3
//   1 <= q <= 10^5

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    vector<string> expected;  // multi-line expected
};

void solve() {
    // TODO: Implement using prefix sums
}

void run_tests() {
    vector<TestCase> tests = {
        {"5\n-2 0 3 -5 2\n3\n0 2\n2 4\n0 4\n",
         {"1", "-2", "-2"}},
        {"4\n1 2 3 4\n2\n0 3\n1 2\n",
         {"10", "5"}},
        {"1\n5\n1\n0 0\n",
         {"5"}},
        {"3\n-1 -1 -1\n3\n0 2\n0 0\n1 2\n",
         {"-3", "-1", "-2"}},
        {"6\n0 0 0 0 0 0\n4\n0 5\n1 4\n2 3\n0 0\n",
         {"0", "0", "0", "0"}},
        {"5\n10 -5 3 -2 7\n5\n0 0\n0 4\n1 3\n2 2\n4 4\n",
         {"10", "13", "-4", "3", "7"}},
        {"2\n-100 50\n1\n0 1\n",
         {"-50"}},
        {"8\n1 2 3 4 5 6 7 8\n3\n0 7\n3 5\n0 0\n",
         {"36", "15", "1"}},
        {"4\n-1 1 -1 1\n4\n0 1\n1 2\n2 3\n0 3\n",
         {"0", "0", "0", "0"}},
        {"3\n1000 2000 3000\n2\n0 1\n1 2\n",
         {"3000", "5000"}},
        {"5\n5 4 3 2 1\n3\n0 4\n1 3\n2 2\n",
         {"15", "9", "3"}},
        {"2\n-1 -1\n1\n0 1\n",
         {"-2"}},
        {"7\n2 -2 2 -2 2 -2 2\n4\n0 6\n0 0\n3 5\n2 4\n",
         {"0", "2", "-2", "2"}},
        {"4\n10 10 10 10\n2\n0 3\n1 2\n",
         {"40", "20"}},
        {"6\n1 -1 1 -1 1 -1\n3\n0 5\n0 2\n3 5\n",
         {"0", "1", "-1"}},
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

        // Join expected with newlines
        string expected_joined;
        for (size_t j = 0; j < tests[i].expected.size(); ++j) {
            expected_joined += tests[i].expected[j];
            if (j + 1 < tests[i].expected.size()) expected_joined += "\n";
        }

        if (actual == expected_joined) {
            cout << "\033[32m[PASS]\033[0m Test " << (i + 1) << endl;
        } else {
            cout << "\033[31m[FAIL]\033[0m Test " << (i + 1)
                 << "\n  Expected: " << expected_joined
                 << "\n  Actual:   " << actual << endl;
        }
    }
}

int main() {
    run_tests();
    return 0;
}
