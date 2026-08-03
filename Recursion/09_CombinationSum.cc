#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::istringstream, std::ostringstream;
using std::string, std::vector;

static constexpr auto GREEN = "\033[32m";
static constexpr auto RED   = "\033[31m";
static constexpr auto RESET = "\033[0m";

void dfs(int i, int target, const vector<int>& arr, vector<int>& cur, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(cur);
        return;
    }
    if (i == static_cast<int>(arr.size()) || target < 0) return;

    cur.push_back(arr[static_cast<size_t>(i)]);
    dfs(i, target - arr[static_cast<size_t>(i)], arr, cur, res);
    cur.pop_back();

    dfs(i + 1, target, arr, cur, res);
}

void solve() {
    int target, n;
    cin >> target >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) cin >> candidates[i];

    vector<vector<int>> res;
    vector<int> cur;
    dfs(0, target, candidates, cur, res);

    if (res.empty()) {
        cout << "Empty";
        return;
    }

    for (auto& r : res) std::sort(r.begin(), r.end());
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());

    for (size_t i = 0; i < res.size(); ++i) {
        for (size_t j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << (j == res[i].size() - 1 ? "" : " ");
        if (i < res.size() - 1) cout << ",";
    }
}

struct TestCase {
    string input;
    string expected;
};

static void trim_right(std::string& s) {
    while (!s.empty() && std::isspace(s.back()))
        s.pop_back();
}

void run_tests() {
    vector<TestCase> tests = {
        {"7 4 2 3 6 7", "2 2 3,7"},
        {"8 3 2 3 5", "2 2 2 2,2 3 3,3 5"},
        {"2 3 2 3 5", "2"},
        {"1 1 2", "Empty"},
        {"4 2 1 2", "1 1 1 1,1 1 2,2 2"},
        {"3 1 2", "Empty"}   };

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        istringstream ss_in(tests[i].input);
        ostringstream ss_out;

        auto* cin_buf = cin.rdbuf(ss_in.rdbuf());
        auto* cout_buf = cout.rdbuf(ss_out.rdbuf());

        try {
            solve();
        } catch (...) {
            cout.rdbuf(cout_buf);
            cin.rdbuf(cin_buf);
            cout << "Runtime Error in Test " << i << endl;
            continue;
        }

        cin.rdbuf(cin_buf);
        cout.rdbuf(cout_buf);

        string actual = ss_out.str();
        trim_right(actual);
        string expected = tests[i].expected;
        trim_right(expected);

        if (actual == expected) {
            cout << GREEN << "[PASS] Test " << i << RESET << endl;
            ++passed;
        } else {
            cout << RED << "[FAIL] Test " << i << RESET << endl;
            cout << "  Input:    " << tests[i].input << endl;
            cout << "  Expected: " << expected << endl;
            cout << "  Actual:   " << actual << endl;
        }
    }
    cout << "Passed " << passed << "/" << tests.size() << " tests." << endl;
}

int main() { run_tests(); }
