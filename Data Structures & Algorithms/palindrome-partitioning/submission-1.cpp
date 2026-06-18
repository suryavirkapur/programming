#include "dsa/dsa.hpp"
using namespace std;

class Solution {
private:
    bool isPalindrome(const string &s) {
        int l = 0;
        int r = s.size() - 1;
        while (l<r) {
            if (s[l] != s[r]) return false;
            r--;
            l++;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &res, string &s, vector<string> &curr, int start) {
        if (s.size() == start) {
            res.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s.substr(start, end-start+1))){
                curr.push_back(s.substr(start, end-start+1));
                backtrack(res,s,curr,end+1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(res, s, curr, 0);
        return res;
    }
};

int main() { return 0; }
