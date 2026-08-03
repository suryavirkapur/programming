// Link: https://leetcode.com/problems/alien-dictionary/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin, std::cout, std::endl, std::string, std::vector;
using std::unordered_map, std::queue;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;

        for (const auto& w : words)
            for (char c : w)
                inDegree[c] = 0;

        for (size_t i = 0; i + 1 < words.size(); ++i) {
            const auto& w1 = words[i];
            const auto& w2 = words[i + 1];
            size_t len = std::min(w1.length(), w2.length());

            if (w1.length() > w2.length() && w1.substr(0, len) == w2) return "";

            for (size_t j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    ++inDegree[w2[j]];
                    break;
                }
            }
        }

        queue<char> q;
        for (const auto& [ch, deg] : inDegree)
            if (deg == 0) q.push(ch);

        string result;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result += u;

            if (adj.contains(u))
                for (char v : adj[u])
                    if (--inDegree[v] == 0)
                        q.push(v);
        }

        return result.length() == inDegree.size() ? result : "";
    }
};

struct TestCase {
    vector<string> words;
    string expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
        {{"wrt","wrf","er","ett","rftt"}, "wertf"},
        {{"z","x"}, "zx"},
        {{"z","x","z"}, ""}
    };

    bool all_passed = true;
    for (size_t i = 0; i < cases.size(); ++i) {
        string result = sol.alienOrder(cases[i].words);

        bool passed = (cases[i].expected.empty())
            ? (result.empty())
            : (result == cases[i].expected);

        if (passed) {
            cout << "Test Case " << (i + 1) << ": PASSED" << endl;
        } else {
            cout << "Test Case " << (i + 1) << ": FAILED (Expected " << cases[i].expected << ", Got " << result << ")" << endl;
            all_passed = false;
        }
    }

    if (all_passed) cout << "\nAll test cases PASSED!" << endl;
    else cout << "\nSome test cases FAILED." << endl;
}
