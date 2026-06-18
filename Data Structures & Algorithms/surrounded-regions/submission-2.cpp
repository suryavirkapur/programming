#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        if (row == 0 || col == 0)
            return;

        vector<vector<char>> res(row, vector<char>(col, 'X'));

        queue<pair<int, int>> q;

        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Instead of looking for regions to flip, try looking for regions that
        // cannot be flipped. Which 'O' cells are guaranteed to stay as 'O'?
        // Start from the edges and work your way inward.

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Check if current cell is an 'O' AND is on any of the 4 edges
                if (board[i][j] == 'O') {
                    if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                        res[i][j] = 'O';
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();
            for (auto dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nc >= 0 && nc < col && nr < row &&
                    board[nr][nc] == 'O' && res[nr][nc] == 'X') {
                    res[nr][nc] =  'O';
                    q.push({nr, nc});
                }
            }
        }
        board = res;
    }
};

int main() { return 0; }
