#include "dsa/dsa.hpp"
using namespace std;

using vi = vector<int>;
using vii = vector<vector<int>>;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool hasX = false;
        bool hasY = false;
        bool hasZ = false;

        for (auto& t : triplets) {
            // Reject triplets that would overshoot target
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            if (t[0] == target[0]) hasX = true;
            if (t[1] == target[1]) hasY = true;
            if (t[2] == target[2]) hasZ = true;
        }

        return hasX && hasY && hasZ;
    }
};

int main() { return 0; }
