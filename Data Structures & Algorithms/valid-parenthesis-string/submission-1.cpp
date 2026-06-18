#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> left;
        stack<int> star;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                left.push(i);
            } else if (c == '*') {
                star.push(i);
            }
            else {
                if (!left.empty()) {
                    int l = left.top();
                    left.pop();
                } else if (!star.empty()) {
                    int s = star.top();
                    star.pop();
                } else {
                    return false;
                }
            }
        }

        while (!left.empty() && !star.empty()) {
            int l = left.top(); 
            int r = star.top(); 
            if (r > l) {
                left.pop();
                star.pop();
            }
            if (l > r) return false;
        }
        
        return left.empty();
    }
};

int main() { return 0; }
