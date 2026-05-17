class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if (row <= 0 || col <= 0) return -1;
        queue<pair<int,int>> q;
        int freshCount = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
                if (grid[i][j] == 1) freshCount++;
            }
        }

        if (freshCount == 0) return 0;
        int currentMinute = 0;

        while (q.size() != 0) {
            int qLen = q.size();
            vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};

            for (int k = 0; k < qLen; k++) {
                pair<int,int> curr = q.front(); q.pop();
                for (auto l : dirs) {
                    int dx =  curr.first + l.first;
                    int dy = curr.second + l.second;


                    if (dx < 0 || dx >= row || dy < 0 || dy >= col || grid[dx][dy] != 1) continue;

                    grid[dx][dy] = 2;
                    q.push({dx,dy});
                    freshCount--;
                }
            }
            if (!q.empty()) currentMinute++;
        }

        return freshCount == 0 ? currentMinute : -1;
    }
};
