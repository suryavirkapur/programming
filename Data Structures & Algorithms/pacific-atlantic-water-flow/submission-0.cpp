#include "dsa/dsa.hpp"
using namespace std;

class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return {};

        int row = grid.size();
        int col = grid[0].size();

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<pair<int, int>> pacificQ;
        queue<pair<int, int>> atlanticQ;

        set<vector<int>> flowFromPacific;
        set<vector<int>> flowFromAtlantic;

        vector<vector<int>> visitedPacific(row, vector<int> (col, 0));
        vector<vector<int>> visitedAtlantic(row, vector<int> (col, 0));

        for (int i = 0; i < col; i++) {
            int lastRow = row - 1;
            pacificQ.push({0, i}); flowFromPacific.insert({0,i});
            atlanticQ.push({lastRow, i}); flowFromAtlantic.insert({lastRow,i});
        }
        atlanticQ.push({0, col - 1}); flowFromAtlantic.insert({0, col - 1});
        for (int i = 1; i < row; i++) {
            int lastCol = col - 1;
            pacificQ.push({i, 0}); flowFromPacific.insert({i,0});
            atlanticQ.push({i, lastCol}); flowFromAtlantic.insert({i, lastCol});
        }
        pacificQ.push({row - 1, 0}); flowFromPacific.insert({row - 1, 0});

        while (!pacificQ.empty()) {
            pair<int, int> point = pacificQ.front();
            pacificQ.pop();
            int r = point.first;
            int c = point.second;

            for (auto [x, y] : dirs) {
                int nr = r + x;
                int nc = c + y;

                if (nr < row && nr >= 0 && nc < col && nc >= 0) {
                    if (!visitedPacific[nr][nc] && grid[nr][nc] >= grid[r][c]) {
                        flowFromPacific.insert({nr, nc});
                        pacificQ.push({nr,nc});
                        visitedPacific[nr][nc] =  1;
                    }
                }
            }
        }

        while (!atlanticQ.empty()) {
            pair<int, int> point = atlanticQ.front();
            atlanticQ.pop();
            int r = point.first;
            int c = point.second;

            for (auto [x, y] : dirs) {
                int nr = r + x;
                int nc = c + y;

                if (nr < row && nr >= 0 && nc < col && nc >= 0) {
                    if (!visitedAtlantic[nr][nc] && grid[nr][nc] >= grid[r][c]) {
                        flowFromAtlantic.insert({nr, nc});
                        atlanticQ.push({nr,nc});
                        visitedAtlantic[nr][nc] =  1;
                    }
                }
            }
        }

        vector<vector<int>> unionSet(flowFromAtlantic.size() + flowFromPacific.size());

        auto it = set_intersection(flowFromAtlantic.begin(), flowFromAtlantic.end(),
                            flowFromPacific.begin(), flowFromPacific.end(), unionSet.begin());

        unionSet.resize(it - unionSet.begin());

        return unionSet;
    }
};

int main() { return 0; }
