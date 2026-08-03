class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int max = 0;
        for (int i = 0;  i < prices.size();i++) {
            int l = i, r= prices.size() - 1;
            while (l <= r) {
                cout << prices[l] << " " << prices[r] << endl;
            if (prices[r] - prices[l] > max) max = prices[r] - prices[l];
            r--;
            }
        }
        
        return max;
    }
};
