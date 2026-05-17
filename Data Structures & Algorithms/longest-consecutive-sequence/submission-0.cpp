class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            int curr_len = 1;
            if (!s.count(x - 1)) {
                int curr = x;
                while (s.count(curr + 1) >= 1) {
                    curr++;
                    curr_len++;
                }
            }
            best = max(best, curr_len);
        }

        return best;
    }
};