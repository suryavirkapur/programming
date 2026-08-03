using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int eraseOverlapIntervals(vvi& intervals) {
        int ops = 0;
        auto cmp = [&](const vi &A, const vi &B) {
            return B[1] > A[1];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int currentStart = intervals[i][0];

            if (currentStart < prevEnd) {
                ops++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else {
                prevEnd = intervals[i][1];
            }
        }
        return ops;
    }
};