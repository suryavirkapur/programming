#include "dsa/dsa.hpp"
using namespace std;

class Solution {
private:
    bool backtrack(int start, string &s, vector<string>& wordDict, vector<int> &memo) {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];
        bool ans = false;
        for (const string &w : wordDict) {
            if (s.compare(start, w.size(), w) == 0) {
                if (backtrack(start+w.size(), s, wordDict, memo)) {
                    memo[start] = 1;
                    return true;
                }
            }
        }
        memo[start] = 0;
        return ans == 1;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size() + 1, -1);
        return backtrack(0, s, wordDict, memo);
    }
};

int main() { return 0; }
