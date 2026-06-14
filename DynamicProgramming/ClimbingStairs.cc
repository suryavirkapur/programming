// LC Problem: https://leetcode.com/problems/climbing-stairs/
// The Pattern is Just Fibonacci Sequence

#include <algorithm>

using std::swap;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;

        int first = 1;
        int second = 1;

        for (int i = 2; i <= n; ++i) {
            int current = first + second;
            swap(first, second);
            second = current;
        }

        return second;
    }
};
