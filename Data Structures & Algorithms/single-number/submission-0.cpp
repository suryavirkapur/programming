// Single Number — find the element that appears only once (XOR trick).
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class SingleNumber {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int n : nums) a ^= n;
        return a;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    SingleNumber sn;

    runner.test("example 1", [&] {
        vector<int> nums = {2,2,1};
        ASSERT_EQ(sn.singleNumber(nums), 1);
    });
    runner.test("example 2", [&] {
        vector<int> nums = {4,1,2,1,2};
        ASSERT_EQ(sn.singleNumber(nums), 4);
    });
    runner.test("single element", [&] {
        vector<int> nums = {1};
        ASSERT_EQ(sn.singleNumber(nums), 1);
    });
    runner.test("larger case", [&] {
        vector<int> nums = {7,3,5,3,5,7,9};
        ASSERT_EQ(sn.singleNumber(nums), 9);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
