class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;

        for(auto &interval : intervals) {
            if (inserted) {
                res.push_back(interval);
            }
            else if ( interval[1] < newInterval[0]) {
                res.push_back(interval);
            }
            else if ( newInterval[1] < interval[0]) {
                res.push_back(newInterval);
                res.push_back(interval);
                inserted = true;
            } else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
            
            // we have appended all intervals

            // we reach an interval where start value is greater than new interval's end 

            // we find an overlapping interval

        }

        if (!inserted) res.push_back(newInterval);

        return res;
    }
};
