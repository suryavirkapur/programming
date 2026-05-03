// Link: https://leetcode.com/problems/number-of-islands/
#include <array>
#include <iostream>
#include <utility>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;

class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());

        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        static constexpr std::array<std::pair<int, int>, 4> dirs = {{{1,0}, {-1,0}, {0,1}, {0,-1}}};
        for (const auto& [dr, dc] : dirs)
            dfs(grid, r + dr, c + dc);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
        return count;
    }
};

struct TestCase {
    vector<vector<char>> grid;
    int expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
        {
            {
                {'1','1','1','1','0'},
                {'1','1','0','1','0'},
                {'1','1','0','0','0'},
                {'0','0','0','0','0'}
            },
            1
        },
        {
            {
                {'1','1','0','0','0'},
                {'1','1','0','0','0'},
                {'0','0','1','0','0'},
                {'0','0','0','1','1'}
            },
            3
        }
    };

    bool all_passed = true;
    for (size_t i = 0; i < cases.size(); ++i) {
        auto grid_copy = cases[i].grid;
        int result = sol.numIslands(grid_copy);
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
