// Buy and Sell Crypto — max profit from a single buy/sell.
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class BuyAndSellCrypto {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < (int)prices.size(); i++) {
            int l = i, r = (int)prices.size() - 1;
            while (l <= r) {
                if (prices[r] - prices[l] > maxProfit)
                    maxProfit = prices[r] - prices[l];
                r--;
            }
        }
        return maxProfit;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    BuyAndSellCrypto bsc;

    runner.test("example 1", [&] {
        vector<int> prices = {7,1,5,3,6,4};
        ASSERT_EQ(bsc.maxProfit(prices), 5);
    });
    runner.test("no profit possible", [&] {
        vector<int> prices = {7,6,4,3,1};
        ASSERT_EQ(bsc.maxProfit(prices), 0);
    });
    runner.test("single day", [&] {
        vector<int> prices = {5};
        ASSERT_EQ(bsc.maxProfit(prices), 0);
    });
    runner.test("two days profit", [&] {
        vector<int> prices = {1,5};
        ASSERT_EQ(bsc.maxProfit(prices), 4);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
