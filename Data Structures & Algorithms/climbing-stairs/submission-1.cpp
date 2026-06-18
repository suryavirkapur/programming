// Climbing Stairs — count distinct ways to climb n stairs (1 or 2 steps).
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class ClimbingStairs {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        if (n <= 2) return dp[n];

        for (int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    ClimbingStairs cs;

    runner.test("n = 2",  [&] { ASSERT_EQ(cs.climbStairs(2), 2); });
    runner.test("n = 3",  [&] { ASSERT_EQ(cs.climbStairs(3), 3); });
    runner.test("n = 4",  [&] { ASSERT_EQ(cs.climbStairs(4), 5); });
    runner.test("n = 5",  [&] { ASSERT_EQ(cs.climbStairs(5), 8); });
    runner.test("n = 1",  [&] { ASSERT_EQ(cs.climbStairs(1), 1); });
    runner.test("n = 10", [&] { ASSERT_EQ(cs.climbStairs(10), 89); });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
