class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        string res = "";

        for (int i = 0; i < n; i++) {
            // odd length 
            int l = i; int r = i;
            while ( l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > res.size()) res = s.substr(l, r - l + 1);
                l--;
                r++;
            }
            // even legnth
            l = i;  r = i + 1;
            while ( l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > res.size()) res = s.substr(l, r - l + 1);
                l--;
                r++;
            }
        }

        return res;
    }
};
