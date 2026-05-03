// Got Base Case Wrong

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    int rob(const vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        if (n == 1) return nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

        return dp[n - 1];
    }
};
