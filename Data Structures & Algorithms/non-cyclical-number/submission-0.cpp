using i64 = long long;
class Solution {
public:
    i64 calc(i64 n) {
        string s = to_string(n);
        i64 sq = 0;
        for (auto c : s) {
            int q = c - '0';
            sq += (q*q);
        }
        return sq;
    } 
    bool isHappy(i64 n) {
        unordered_set<i64> st;
        
        while(n != 1) {
            if (st.count(n)) {
                return false;
            }
            st.insert(n);
            n = calc(n);
        }

        return true;
    }
};
