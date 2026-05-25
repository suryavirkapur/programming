class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
    }
    private: 
    int robLinear(vector<int> &nums, int start, int end) {
        if (start ==  end) return nums[start];

        int prev = nums[start];
        int curr = max(prev, nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            int temp = curr;
            curr = max(prev+nums[i], curr);
            prev = temp;
        }

        return curr;
    }
};
