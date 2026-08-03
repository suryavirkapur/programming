// Link: https://leetcode.com/problems/course-schedule/
#include <iostream>
#include <queue>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;
using std::queue;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            ++inDegree[edge[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (inDegree[i] == 0) q.push(i);

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++count;

            for (int v : adj[u])
                if (--inDegree[v] == 0)
                    q.push(v);
        }

        return count == numCourses;
    }
};

struct TestCase {
    int numCourses;
    vector<vector<int>> prerequisites;
    bool expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
        {2, {{1, 0}}, true},
        {2, {{1, 0}, {0, 1}}, false},
        {4, {{1, 0}, {2, 1}, {3, 2}}, true},
        {3, {{0, 1}, {0, 2}, {1, 2}}, true}
    };

    bool all_passed = true;
    for (size_t i = 0; i < cases.size(); ++i) {
        bool result = sol.canFinish(cases[i].numCourses, cases[i].prerequisites);
        if (result == cases[i].expected) {
            cout << "Test Case " << (i + 1) << ": PASSED" << endl;
        } else {
            cout << "Test Case " << (i + 1) << ": FAILED (Expected " << cases[i].expected << ", Got " << result << ")" << endl;
            all_passed = false;
        }
    }

    if (all_passed) cout << "\nAll test cases PASSED!" << endl;
    else cout << "\nSome test cases FAILED." << endl;
}
