class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        nth_element(nums.begin(), nums.begin() + index, nums.end());
        return nums[index];
    }
};
