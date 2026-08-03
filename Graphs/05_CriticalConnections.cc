// Link: https://leetcode.com/problems/critical-connections-in-a-network/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;

class Solution {
    vector<vector<int>> adj_;
    vector<int> disc_, low_;
    vector<vector<int>> bridges_;
    int timer_ = 0;

    void dfs(int u, int p = -1) {
        disc_[u] = low_[u] = timer_++;

        for (int v : adj_[u]) {
            if (v == p) continue;

            if (disc_[v] != -1) {
                low_[u] = std::min(low_[u], disc_[v]);
            } else {
                dfs(v, u);
                low_[u] = std::min(low_[u], low_[v]);
                if (low_[v] > disc_[u])
                    bridges_.push_back({u, v});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj_.assign(n, vector<int>());
        for (const auto& edge : connections) {
            adj_[edge[0]].push_back(edge[1]);
            adj_[edge[1]].push_back(edge[0]);
        }

        disc_.assign(n, -1);
        low_.assign(n, -1);
        bridges_.clear();
        timer_ = 0;

        for (int i = 0; i < n; ++i)
            if (disc_[i] == -1) dfs(i);

        for (auto& b : bridges_) std::sort(b.begin(), b.end());
        std::sort(bridges_.begin(), bridges_.end());

        return bridges_;
    }
};

struct TestCase {
    int n;
    vector<vector<int>> connections;
    vector<vector<int>> expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
        {4, {{0,1},{1,2},{2,0},{1,3}}, {{1,3}}},
        {2, {{0,1}}, {{0,1}}}
    };

    bool all_passed = true;
    for (size_t i = 0; i < cases.size(); ++i) {
        auto result = sol.criticalConnections(cases[i].n, cases[i].connections);

        auto expected = cases[i].expected;
        for (auto& b : expected) std::sort(b.begin(), b.end());
        std::sort(expected.begin(), expected.end());

        if (result == expected) {
            cout << "Test Case " << (i + 1) << ": PASSED" << endl;
        } else {
            cout << "Test Case " << (i + 1) << ": FAILED" << endl;
            all_passed = false;
        }
    }

    if (all_passed) cout << "\nAll test cases PASSED!" << endl;
    else cout << "\nSome test cases FAILED." << endl;
}
