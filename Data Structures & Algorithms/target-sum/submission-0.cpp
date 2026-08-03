class Solution {
private:
    map< pair<int,int> ,int> memo;
public:
    int dfs(vector<int> &nums, int target, int i, int s) {
        if (i == nums.size()) {
            if (s == target) return 1;
            return 0;
        }

        if (memo.count({i, s})) {
            return memo[{i,s}];
        }

        int addWays = dfs(nums, target, i + 1, s + nums[i]);
        int subWays = dfs(nums, target, i + 1, s - nums[i]);

        memo[{i,s}] = addWays + subWays;
        return memo[{i,s}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }
};
