class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [] (const pair<int,int> &a, const pair<int,int> &b) {
            return a.first < b.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>,decltype(comp)> pq(comp);

        for (int i = 0;  i < points.size(); i++) {
            int x = points[i][0]; int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist, i});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        res.reserve(pq.size());

        while (!pq.empty()) {int index = pq.top().second; pq.pop(); res.push_back(points[index]);};
        return res;
    }
};
