// Link: https://leetcode.com/problems/network-delay-time/
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using std::cin, std::cout, std::endl, std::vector, std::pair;
using std::priority_queue, std::greater;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& t : times) {
            auto [u, v, w] = std::tuple<int, int, int>(t[0], t[1], t[2]);
            adj[u].push_back({v, w});
        }

        using State = pair<int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        constexpr auto INF = std::numeric_limits<int>::max();
        vector<int> dist(n + 1, INF);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        auto max_dist = *std::max_element(dist.begin() + 1, dist.end());
        return max_dist == INF ? -1 : max_dist;
    }
};

struct TestCase {
    vector<vector<int>> times;
    int n;
    int k;
    int expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
        {
            {{2,1,1}, {2,3,1}, {3,4,1}},
            4, 2, 2
        },
        {
            {{1,2,1}},
            2, 1, 1
        },
        {
            {{1,2,1}},
            2, 2, -1
        }
    };

    bool all_passed = true;
    for (size_t i = 0; i < cases.size(); ++i) {
        int result = sol.networkDelayTime(cases[i].times, cases[i].n, cases[i].k);
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
