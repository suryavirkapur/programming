class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);
       
        int curr = 0;
        int prev = 0;
        
        for (int i = 2; i  <= n ; i ++) {
            int t = curr;
            curr = min(prev + cost[i-2], curr +  cost[i-1]);
            prev = t;
        }

        return curr;
    }
};
