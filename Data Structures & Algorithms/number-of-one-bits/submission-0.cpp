// Number of One Bits — Hamming weight (popcount).
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class HammingWeight {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    HammingWeight hw;

    runner.test("example 1 — 11 (0b1011)", [&] {
        ASSERT_EQ(hw.hammingWeight(11), 3);
    });
    runner.test("example 2 — 128 (0b10000000)", [&] {
        ASSERT_EQ(hw.hammingWeight(128), 1);
    });
    runner.test("example 3 — 2147483645", [&] {
        ASSERT_EQ(hw.hammingWeight(2147483645), 30);
    });
    runner.test("zero", [&] {
        ASSERT_EQ(hw.hammingWeight(0), 0);
    });
    runner.test("all ones in byte", [&] {
        ASSERT_EQ(hw.hammingWeight(255), 8);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
