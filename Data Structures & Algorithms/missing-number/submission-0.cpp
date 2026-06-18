// Missing Number — find the missing number in range [0, n].
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class MissingNumber {
public:
    int missingNumber(vector<int>& nums) {
        int res = (int)nums.size();
        for (int i = 0; i < (int)nums.size(); i++) {
            res += i - nums[i];
        }
        return res;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    MissingNumber mn;

    runner.test("example 1", [&] {
        vector<int> nums = {3,0,1};
        ASSERT_EQ(mn.missingNumber(nums), 2);
    });
    runner.test("example 2", [&] {
        vector<int> nums = {0,1};
        ASSERT_EQ(mn.missingNumber(nums), 2);
    });
    runner.test("example 3", [&] {
        vector<int> nums = {9,6,4,2,3,5,7,0,1};
        ASSERT_EQ(mn.missingNumber(nums), 8);
    });
    runner.test("missing zero", [&] {
        vector<int> nums = {1,2,3};
        ASSERT_EQ(mn.missingNumber(nums), 0);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
