#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxAreaTillNow = 0;
    // TODO: implement
    int l = 0;
    int maxHeightLeft = height[l];
    for (int r = 1; r < height.size(); r++) {
      maxHeightLeft = max(maxHeightLeft, height[r]);
      maxAreaTillNow = max(maxAreaTillNow, maxHeightLeft);
    }
  }
};
