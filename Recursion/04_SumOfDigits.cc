#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::istringstream, std::ostringstream;
using std::string, std::vector;

static constexpr auto GREEN = "\033[32m";
static constexpr auto RED   = "\033[31m";
static constexpr auto RESET = "\033[0m";

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

void solve() {
    int n;
    cin >> n;
    cout << sumDigits(std::abs(n));
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
        {"123", "6"},
        {"0", "0"},
        {"999", "27"},
        {"4567", "22"},
        {"101", "2"},
        {"11111", "5"}    };

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
