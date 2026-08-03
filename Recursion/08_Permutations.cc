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

void permute(string& s, int l, int r, vector<string>& res) {
    if (l == r) {
        res.push_back(s);
    } else {
        for (int i = l; i <= r; ++i) {
            std::swap(s[l], s[i]);
            permute(s, l + 1, r, res);
            std::swap(s[l], s[i]);
        }
    }
}

void solve() {
    string s;
    cin >> s;
    vector<string> res;
    permute(s, 0, static_cast<int>(s.length()) - 1, res);
    std::sort(res.begin(), res.end());

    for (size_t i = 0; i < res.size(); ++i)
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
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
        {"abc", "abc acb bac bca cab cba"},
        {"ab", "ab ba"},
        {"a", "a"},
        {"xyz", "xyz xzy yxz yzx zxy zyx"},
        {"12", "12 21"},
        {"aab", "aab aab aba aba baa baa"}    };

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
