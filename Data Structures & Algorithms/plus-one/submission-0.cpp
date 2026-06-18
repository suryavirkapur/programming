// Plus One — add one to a number represented as a vector of digits.
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class PlusOne {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size();
        for (int i = n-1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    PlusOne po;

    runner.test("example 1", [&] {
        vector<int> digits = {1,2,3};
        vector<int> expected = {1,2,4};
        ASSERT_VEC_EQ(po.plusOne(digits), expected);
    });
    runner.test("example 2 — carry", [&] {
        vector<int> digits = {4,3,2,1};
        vector<int> expected = {4,3,2,2};
        ASSERT_VEC_EQ(po.plusOne(digits), expected);
    });
    runner.test("all nines", [&] {
        vector<int> digits = {9,9,9};
        vector<int> expected = {1,0,0,0};
        ASSERT_VEC_EQ(po.plusOne(digits), expected);
    });
    runner.test("single digit", [&] {
        vector<int> digits = {5};
        vector<int> expected = {6};
        ASSERT_VEC_EQ(po.plusOne(digits), expected);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
