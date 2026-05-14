#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main() {
  int n, m;
  cin >> n >> m;
  int sx, sy;
  int tx, ty;
  vector<vector<char>> grid (n, vector<char> (m));
  vector<vector<int>> path (n, vector<int> (m, -1));
  for (int i  = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        sx = i;
        sy = j;
      }
      if (grid[i][j] == 'B') {
        tx = i;
        ty = j;
      }
    }
  }

  int depth = 0;

  queue<pair<int,int>> q;
  q.push({sx,sy});
  grid[sx][sy] = '#';
  while (!q.empty()) {
    int levelSize = q.size();

    for (int i = 0; i < levelSize; i++){
      auto [x,y] = q.front(); q.pop();

      if (x == tx && y == ty){
       cout << "YES\n" << depth << endl;
       string currPath = "";
       string pathMap = "DURL";
       while (x != sx || y != sy){
         char d = pathMap[path[x][y]];
         currPath+=d;

         switch (d) {
           case 'U': x++;  break;
           case 'D': x--;  break;
           case 'R': y--;  break;
           case 'L': y++;  break;
         }
       }
       reverse(currPath.begin(), currPath.end());
       cout << currPath  << endl;
       return 0;  
      }

      for (int index = 0; auto [dx,dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          if (grid[nx][ny] != '#') {
            q.push({nx,ny});
            path[nx][ny] = index;
            grid[nx][ny] = '#';
          }
        }
        
        index++;
      }
    }
    depth++;
  }


  cout << "NO\n";
}
