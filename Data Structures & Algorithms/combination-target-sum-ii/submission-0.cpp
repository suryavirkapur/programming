class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int> &nums, int t, int s) {
        
        if (t < 0) return;
        if (t == 0) {
            res.push_back(path);
            return;
        }

        for (int i = s; i < nums.size(); i++) {
            if (i > s && nums[i] == nums[i-1])continue;
            if (nums[i] > t) return;
            path.push_back(nums[i]);
            backtrack(nums, t - nums[i], i + 1);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0);
        return res;
    }
};
