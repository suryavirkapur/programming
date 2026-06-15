// Problem: Candy
// LC: https://leetcode.com/problems/candy/
//
// Children stand in a line with ratings[i]. Give each child at least 1 candy;
// higher-rated children must get more than immediate neighbors. Minimize total
// candies while satisfying constraints.
//
// Input Format:
//   Line 1: n
//   Line 2: n space-separated ratings
//
// Output Format:
//   Single integer: minimum total candies
//
// Example:
//   Input:  3 / 1 0 2
//   Output: 5
//
// Constraints:
//   n == ratings.length
//   1 <= n <= 2*10^4
//   0 <= ratings[i] <= 2*10^4

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Two-pass greedy (left-to-right then right-to-left)
}

void run_tests() {
    vector<TestCase> tests = {
        {"3\n1 0 2\n",              "5"},
        {"3\n1 2 2\n",              "4"},
        {"5\n1 3 4 5 2\n",          "11"},
        {"1\n1\n",                  "1"},
        {"2\n1 1\n",                "2"},
        {"3\n1 1 1\n",              "3"},
        {"3\n3 2 1\n",              "6"},
        {"5\n1 2 3 4 5\n",          "15"},
        {"5\n5 4 3 2 1\n",          "15"},
        {"3\n0 1 0\n",              "4"},
        {"3\n1 0 1\n",              "5"},
        {"4\n1 3 2 2\n",            "5"},
        {"6\n1 2 87 87 87 2\n",     "10"},
        {"4\n1 2 3 1\n",            "7"},
        {"2\n1 3\n",                "3"},
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
