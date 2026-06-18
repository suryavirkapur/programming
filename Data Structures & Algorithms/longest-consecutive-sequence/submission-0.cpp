// Longest Consecutive Sequence — length of longest consecutive elements.
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class LongestConsecutive {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            int curr_len = 1;
            if (!s.count(x - 1)) {
                int curr = x;
                while (s.count(curr + 1) >= 1) {
                    curr++;
                    curr_len++;
                }
            }
            best = max(best, curr_len);
        }

        return best;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    LongestConsecutive lc;

    runner.test("example 1", [&] {
        vector<int> nums = {100,4,200,1,3,2};
        ASSERT_EQ(lc.longestConsecutive(nums), 4);
    });
    runner.test("example 2", [&] {
        vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
        ASSERT_EQ(lc.longestConsecutive(nums), 9);
    });
    runner.test("empty input", [&] {
        vector<int> nums = {};
        ASSERT_EQ(lc.longestConsecutive(nums), 0);
    });
    runner.test("single element", [&] {
        vector<int> nums = {5};
        ASSERT_EQ(lc.longestConsecutive(nums), 1);
    });
    runner.test("all duplicates", [&] {
        vector<int> nums = {1,1,1,1};
        ASSERT_EQ(lc.longestConsecutive(nums), 1);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
