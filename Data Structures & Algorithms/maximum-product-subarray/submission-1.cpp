#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpa(n);
        vector<int> dpi(n);

        dpa[0] = nums[0];
        dpi[0] = nums[0];

        for (int i = 1; i < n; i++) {
            dpa[i] = max({nums[i], dpa[i-1] * nums[i], dpi[i-1] * nums[i]});
            dpi[i] = min({nums[i], dpa[i-1] * nums[i], dpi[i-1] * nums[i]});
        }

        return *max_element(dpa.begin(), dpa.end());
    }
};

int main() { return 0; }
