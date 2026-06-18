#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // since this is an easy DP problem
        // let's work through it on our own

        // basically what we do is figure out ways to get a point 
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1]; 
        }

        for (int i = 1; i < m;  i++) {
            for (int j = 1; j < n;  j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() { return 0; }
