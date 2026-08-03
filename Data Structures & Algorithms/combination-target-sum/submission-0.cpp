class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        createSubset(nums, 0, target, res, subset);
        return res;
    }

    void createSubset(vector<int>& nums, int index, int target, vector<vector<int>>& res,
                      vector<int>& subset) {
                        if (target < 0) return;
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        if (index >= nums.size()) return;

        subset.push_back(nums[index]);
        createSubset(nums, index, target - nums[index], res, subset);
        subset.pop_back();
        createSubset(nums, index + 1, target, res, subset);
    }
};
