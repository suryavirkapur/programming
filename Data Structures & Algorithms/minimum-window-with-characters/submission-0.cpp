class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0 || s.size() < t.size() ) return "";

        vector<int> mp(128,0); for(char c : t) mp[c]++;
        int left = 0, right = 0, res = INT_MAX, start = 0, required = t.size(); 

        while (right < s.size()) {
            if (mp[s[right]] > 0) {
                required--;
            }
            mp[s[right]]--;
            right++;
            while (required == 0) {
                if (right - left < res) {
                    start = left;
                    res = right - left;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    required++;
                }
                left++;
            }

        }

        return res == INT_MAX ? "" : s.substr(start, res);
    }
};
