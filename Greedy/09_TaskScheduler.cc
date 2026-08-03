// Problem: Task Scheduler
// LC: https://leetcode.com/problems/task-scheduler/
//
// Given tasks (A-Z) and cooldown n, find the minimum time to finish all tasks.
// Same task must be separated by at least n intervals (idle slots allowed).
//
// Input Format:
//   Line 1: tasks (string of uppercase letters)
//   Line 2: n  (cooldown length)
//
// Output Format:
//   Single integer: minimum time units
//
// Example:
//   Input:  AAB / 0
//   Output: 3
//
// Constraints:
//   1 <= tasks.length <= 10^4
//   tasks[i] is an uppercase English letter
//   0 <= n <= 100

#include <bits/stdc++.h>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

void solve() {
    // TODO: Count frequencies; compute max(idle formula, tasks.length)
}

void run_tests() {
    vector<TestCase> tests = {
        {"A\n0\n",                      "1"},
        {"AB\n0\n",                     "2"},
        {"AAB\n0\n",                    "3"},
        {"AA\n1\n",                     "3"},
        {"AAA\n2\n",                    "7"},
        {"AABBBCCDD\n2\n",              "9"},
        {"AABBCBBACCC\n2\n",            "11"},
        {"BBCABDE\n3\n",                "9"},
        {"AAABBB\n2\n",                 "8"},
        {"ABAB\n2\n",                   "5"},
        {"AAAA\n3\n",                   "13"},
        {"ABC\n2\n",                    "3"},
        {"AAAAA\n0\n",                  "5"},
        {"AAAB\n3\n",                   "9"},
        {"ABCD\n2\n",                   "4"},
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
