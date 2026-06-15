// Problem: Partition Labels
// LC: https://leetcode.com/problems/partition-labels/
//
// Split string s into as many parts as possible so each letter appears in at
// most one part. Return the sizes of each partition in order.
//
// Input Format:
//   Line 1: string s (lowercase letters)
//
// Output Format:
//   Space-separated partition sizes
//
// Example:
//   Input:  ababcbacadefegdehijhklij
//   Output: 9 7 8
//
// Constraints:
//   1 <= s.length <= 500
//   s consists of lowercase English letters

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Record last index of each char; greedy expand partition end
}

void run_tests() {
    vector<TestCase> tests = {
        {"ababcbacadefegdehijhklij\n",  "9 7 8"},
        {"eccbbbbdec\n",                "10"},
        {"caedbdedda\n",                "1 9"},
        {"a\n",                         "1"},
        {"aa\n",                        "2"},
        {"ab\n",                        "1 1"},
        {"abc\n",                       "1 1 1"},
        {"abcabd\n",                    "5 1"},
        {"aba\n",                       "3"},
        {"aab\n",                       "2 1"},
        {"abcabc\n",                    "6"},
        {"llllttt\n",                   "4 3"},
        {"qvx\n",                       "1 1 1"},
        {"abacaba\n",                   "7"},
        {"xyxzyx\n",                    "6"},
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
