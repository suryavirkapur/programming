#include "dsa/dsa.hpp"
using namespace std;

class Solution {
    const unordered_map<char, string> keyboard = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    void backtrack(vector<string> &res, string &digits, string  &curr, int index) {
        if (digits.size() ==  index) {
            res.emplace_back(curr);
            return;
        }
        char cc = digits[index];
        for (char c :  keyboard.at(cc)) {
            curr.push_back(c);
            backtrack(res, digits, curr, index + 1);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> res;
        string str;
        backtrack(res, digits, str, 0);
        return res;
    }
};

int main() { return 0; }
