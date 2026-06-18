// House Robber — max loot from non-adjacent houses.
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class HouseRobber {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[n-1];
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    HouseRobber hr;

    runner.test("example 1", [&] {
        vector<int> nums = {1,2,3,1};
        ASSERT_EQ(hr.rob(nums), 4);
    });
    runner.test("example 2", [&] {
        vector<int> nums = {2,7,9,3,1};
        ASSERT_EQ(hr.rob(nums), 12);
    });
    runner.test("single house", [&] {
        vector<int> nums = {5};
        ASSERT_EQ(hr.rob(nums), 5);
    });
    runner.test("two houses", [&] {
        vector<int> nums = {10,20};
        ASSERT_EQ(hr.rob(nums), 20);
    });
    runner.test("empty-like adjacency", [&] {
        vector<int> nums = {2,1,1,2};
        ASSERT_EQ(hr.rob(nums), 4);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
