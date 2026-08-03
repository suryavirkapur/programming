#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin, std::cout, std::endl, std::fixed, std::setprecision;
using std::istringstream, std::ostringstream;
using std::string, std::vector;

static constexpr auto GREEN = "\033[32m";
static constexpr auto RED   = "\033[31m";
static constexpr auto RESET = "\033[0m";

double myPow(double x, int n) {
    if (n == 0) return 1.0;
    double half = myPow(x, n / 2);
    if (n % 2 == 0) return half * half;
    return n > 0 ? half * half * x : half * half / x;
}

void solve() {
    double x;
    int n;
    cin >> x >> n;
    cout << fixed << setprecision(5) << myPow(x, n);
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
        {"2.0 10", "1024.00000"},
        {"2.1 3", "9.26100"},
        {"2.0 -2", "0.25000"},
        {"1.0 100", "1.00000"},
        {"5.0 0", "1.00000"},
        {"0.5 2", "0.25000"}    };

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
