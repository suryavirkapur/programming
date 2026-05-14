#include <bits/stdc++.h>

void dfs(std::vector<std::vector<char>> &grid, int i, int j){
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
  if (grid[i][j] != '.') return;
  grid[i][j] = '#';
  dfs(grid, i + 1, j);
  dfs(grid, i - 1, j);
  dfs(grid, i, j + 1);
  dfs(grid, i, j - 1);
}

int main() {
  int n, m;
  std::cin >> n;
  std::cin >> m;
  std::vector<std::vector<char>> grid(n, std::vector<char> (m));  
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    std::cin >> grid[i][j];
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++){
      if (grid[i][j] == '.') {
        count++;
        dfs(grid, i, j);
      }
    }
  }
  std::cout << std::endl << count;
}
