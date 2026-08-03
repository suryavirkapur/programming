// Link: https://leetcode.com/problems/swim-in-rising-water/
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;
using std::priority_queue, std::greater;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());

        using State = std::tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        static constexpr std::array<std::pair<int, int>, 4> dirs = {{{0,1}, {0,-1}, {1,0}, {-1,0}}};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1) return t;

            for (const auto& [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({std::max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1;
    }
};

struct TestCase {
    vector<vector<int>> grid;
    int expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
        {
            {{0,2},{1,3}},
            3
        },
        {
            {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}},
            16
        }
    };

    bool all_passed = true;
    for (size_t i = 0; i < cases.size(); ++i) {
        int result = sol.swimInWater(cases[i].grid);
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
