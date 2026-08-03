// Problem: Contiguous Array (Longest subarray with equal 0s and 1s)
//
// Given a binary array, find the maximum length of a contiguous subarray
// with an equal number of 0 and 1.
//
// Input Format:
//   First line:  n
//   Second line: n space-separated integers (0s and 1s)
//
// Output Format:
//   Length of the longest contiguous subarray with equal 0s and 1s
//
// Example:
//   Input:  6 / 0 1 0 1
//   Output: 4
//
//   Input:  6 / 0 1 1 1 1 1 0
//   Output: 2
//
// Constraints:
//   1 <= n <= 10^5
//   nums[i] is 0 or 1

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Treat 0 as -1, then use prefix sum hashmap
}

void run_tests() {
    vector<TestCase> tests = {
        {"4\n0 1 0 1\n",          "4"},
        {"6\n0 1 1 1 1 1 0\n",    "2"},
        {"1\n0\n",                "0"},
        {"1\n1\n",                "0"},
        {"2\n0 1\n",              "2"},
        {"2\n0 0\n",              "0"},
        {"2\n1 1\n",              "0"},
        {"6\n1 0 1 0 1 0\n",      "6"},
        {"8\n1 1 0 0 1 1 0 0\n",  "8"},
        {"3\n1 0 0\n",            "2"},
        {"5\n0 0 1 1 0\n",        "4"},
        {"3\n0 1 0\n",            "4"},
        {"4\n1 0 0 1\n",          "4"},
        {"5\n0 1 1 0 1\n",        "4"},
        {"2\n0 1\n",              "2"},
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
