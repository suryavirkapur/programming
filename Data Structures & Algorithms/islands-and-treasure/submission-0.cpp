#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    // Represents a cell in the BFS queue
    struct Cell {
        int row;
        int col;
        int dist;
    };

    void islandsAndTreasure(vector<vector<int>>& rooms) {
        const int INF = 2147483647;
        if (rooms.empty() || rooms[0].empty()) return;

        int rows = rooms.size();
        int cols = rooms[0].size();

        // Start BFS from each treasure (cell with value 0)
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (rooms[i][j] == 0) {
                    bfs(i, j, rooms);
                }
            }
        }
    }

private:
    void bfs(int startRow, int startCol, vector<vector<int>>& rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();
        const int INF = 2147483647;

        // Directions: up, down, left, right
        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<Cell> q;
        q.push({startRow, startCol, 0});

        while (!q.empty()) {
            Cell curr = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int newRow = curr.row + dir.first;
                int newCol = curr.col + dir.second;

                // Check bounds and skip walls (-1) or already better distances
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
                if (rooms[newRow][newCol] == -1) continue; // wall

                int newDist = curr.dist + 1;
                // If we found a shorter path, update and push to queue
                if (newDist < rooms[newRow][newCol]) {
                    rooms[newRow][newCol] = newDist;
                    q.push({newRow, newCol, newDist});
                }
            }
        }
    }
};

int main() { return 0; }
