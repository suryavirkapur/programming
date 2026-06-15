// Problem: 2D Prefix Sum - Matrix Block Sum
//
// Given a 2D matrix, preprocess it so that submatrix sum queries
// (r1, c1, r2, c2) can be answered in O(1).
//
// Input Format:
//   First line:  rows cols
//   Next rows lines: row of matrix (space-separated)
//   Next line:      q
//   Next q lines:   r1 c1 r2 c2
//
// Output Format:
//   q lines, each the sum of the submatrix
//
// Example:
//   Input:
//     3 3
//     1 2 3
//     4 5 6
//     7 8 9
//     2
//     0 0 1 1
//     1 1 2 2
//   Output:
//     12
//     28
//
// Constraints:
//   1 <= rows, cols <= 200
//   -10^3 <= matrix[i][j] <= 10^3

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    vector<string> expected;
};

void solve() {
    // TODO: Build 2D prefix sum
}

void run_tests() {
    vector<TestCase> tests = {
        {"3 3\n1 2 3\n4 5 6\n7 8 9\n2\n0 0 1 1\n1 1 2 2\n",
         {"12", "28"}},
        {"1 1\n5\n1\n0 0 0 0\n",
         {"5"}},
        {"2 2\n1 1\n1 1\n1\n0 0 1 1\n",
         {"4"}},
        {"2 3\n1 2 3\n4 5 6\n2\n0 0 0 2\n0 0 1 2\n",
         {"6", "21"}},
        {"3 3\n0 0 0\n0 0 0\n0 0 0\n1\n1 1 1 1\n",
         {"0"}},
        {"3 3\n-1 -2 -3\n-4 -5 -6\n-7 -8 -9\n2\n0 0 2 2\n1 1 1 1\n",
         {"-45", "-5"}},
        {"2 2\n10 20\n30 40\n3\n0 0 0 0\n1 1 1 1\n0 0 1 1\n",
         {"10", "40", "100"}},
        {"3 2\n1 2\n3 4\n5 6\n2\n0 1 2 1\n0 0 2 0\n",
         {"12", "9"}},
        {"2 4\n1 2 3 4\n5 6 7 8\n1\n0 0 1 3\n",
         {"36"}},
        {"3 3\n1 1 1\n1 1 1\n1 1 1\n2\n0 0 0 0\n0 0 2 2\n",
         {"1", "9"}},
        {"2 2\n-1 1\n1 -1\n1\n0 0 1 1\n",
         {"0"}},
        {"3 1\n1\n2\n3\n2\n0 0 2 0\n1 0 2 0\n",
         {"6", "5"}},
        {"4 4\n1 0 1 0\n0 1 0 1\n1 0 1 0\n0 1 0 1\n2\n0 0 3 3\n1 1 2 2\n",
         {"8", "4"}},
        {"2 2\n100 100\n100 100\n1\n0 0 1 1\n",
         {"400"}},
        {"3 3\n2 2 2\n2 2 2\n2 2 2\n1\n0 0 2 2\n",
         {"18"}},
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
