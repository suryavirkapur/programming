class Solution {

private: 
    void backtrack(vector<int>&nums, vector<bool> &visited, vector<vector<int>> &res, vector<int> &path){
        if (nums.size() == path.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (visited[i]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, visited, res, path);
            path.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, visited, res, path);
        return res;
    }
};
