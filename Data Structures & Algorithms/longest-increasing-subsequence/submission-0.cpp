class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();

        vector<int> dp(N, 1);

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) dp[i] = 1 + dp[j];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
