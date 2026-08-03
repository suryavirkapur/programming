// Very simpler to Climbing Stairs
// Just with added cost

#include <algorithm>
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        int n = static_cast<int>(cost.size());

        int first = cost[0];
        int second = cost[1];

        if (n < 2) return min(first, second);

        for (int i = 2; i < n; ++i) {
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }

        return min(first, second);
    }
};
