#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(); int l2 = s2.size();
        if (l1 > l2) return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for (int i = 0; i < l1; i++)  {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        if (v1 == v2) return true;
        

        for (int i = l1; i < s2.size(); i++) {
            v2[s2[i - l1] - 'a']--;
            v2[s2[i] - 'a']++;

            if (v1 == v2) return true;
        }

        return false;
    }
};

int main() { return 0; }
