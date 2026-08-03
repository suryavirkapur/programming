// Same as Climbing Stairs

#include <algorithm>

using std::swap;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int first = 0;
        int second = 1;

        for (int i = 2; i <= n; ++i) {
            int current = first + second;
            swap(first, second);
            second = current;
        }

        return second;
    }
};
