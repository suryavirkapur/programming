using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
   public:
    vvi merge(vvi& intervals) {

        auto cmp = [&](const vi& A, const vi& B) { return B[0] > A[0]; };
        sort(intervals.begin(), intervals.end(), cmp);
       
        vvi res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            int lastEnd = res.back()[1];

            if (currStart > lastEnd) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], currEnd);
            }
        }

        
        return res;
    }
};
