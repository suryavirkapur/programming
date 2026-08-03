#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::istringstream, std::ostringstream;
using std::string, std::vector;

static constexpr auto GREEN = "\033[32m";
static constexpr auto RED   = "\033[31m";
static constexpr auto RESET = "\033[0m";

bool isSafe(int row, int col, const vector<string>& board, int n) {
    const int orig_row = row, orig_col = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        --row; --col;
    }

    col = orig_col; row = orig_row;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        --col;
    }

    col = orig_col; row = orig_row;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        ++row; --col;
    }
    return true;
}

void solveNQueens(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; ++row) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solveNQueens(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solveNQueens(0, board, ans, n);
    cout << ans.size();
}

struct TestCase {
    string input;
    string expected;
};

void run_tests() {
    vector<TestCase> tests = {
        {"4", "2"},
        {"1", "1"},
        {"2", "0"},
        {"3", "0"},
        {"5", "10"},
        {"6", "4"}    };

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
        while (!actual.empty() && std::isspace(actual.back())) actual.pop_back();
        string expected = tests[i].expected;
        while (!expected.empty() && std::isspace(expected.back())) expected.pop_back();

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

int main() {
    run_tests();
}
