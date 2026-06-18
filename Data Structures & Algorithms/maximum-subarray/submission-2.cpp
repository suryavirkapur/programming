// Maximum Subarray — Kadane's algorithm.
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class MaximumSubarray {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int curSum = 0;
        for (int i = 0; i < (int)nums.size(); i++){
            if (curSum < 0) curSum = 0;
            int curr = nums[i];

            curSum += curr;
            sum = max(curSum, sum);
        }
        return sum;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    MaximumSubarray ms;

    runner.test("example 1 — mixed", [&] {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        ASSERT_EQ(ms.maxSubArray(nums), 6);
    });
    runner.test("all positive", [&] {
        vector<int> nums = {1,2,3,4};
        ASSERT_EQ(ms.maxSubArray(nums), 10);
    });
    runner.test("single element", [&] {
        vector<int> nums = {5};
        ASSERT_EQ(ms.maxSubArray(nums), 5);
    });
    runner.test("all negative", [&] {
        vector<int> nums = {-5,-2,-3,-1};
        ASSERT_EQ(ms.maxSubArray(nums), -1);
    });
    runner.test("larger mixed", [&] {
        vector<int> nums = {5,4,-1,7,8};
        ASSERT_EQ(ms.maxSubArray(nums), 23);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
