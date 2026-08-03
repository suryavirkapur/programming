class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int total_sum = 0;
    for (int num : nums) {
        total_sum += num;
    }

    if (total_sum % 2 != 0) {
        return false;
    }

    int target = total_sum / 2;
    int n = nums.size();

    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            if (s < nums[i - 1]) {
                dp[i][s] = dp[i - 1][s];
            } else {
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
    }
};
