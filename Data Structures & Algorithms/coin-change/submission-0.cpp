#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int N) {
        vector<int> dp(N+1, N+1);
        dp[0]= 0;
        for (int i = 1; i <= N; i++) {
            for (int & coin : coins) {
                int diff = i - coin;
                if (diff < 0) continue;
                dp[i] =  min(dp[i], dp[diff] + 1);
            }
        }
        return dp[N] == N+1 ? -1 : dp[N];
    }
};

int main() { return 0; }
