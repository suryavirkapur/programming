class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        vector<int> res;
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] > target) {res.push_back(x); freq[x] = -INT_MAX;}
        }
        return res;
    }
};