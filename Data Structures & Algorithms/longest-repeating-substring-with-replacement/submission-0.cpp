class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, res = 0, freq = 0, n = s.size();
        unordered_map<char, int> mp;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            freq = max(freq, mp[s[r]]);
            while (( r - l + 1) - freq >  k) {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1); 
        }

        return res;
    }
};
