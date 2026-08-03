#include <bits/stdc++.h>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> adjList(n, std::vector<int> ());
  for (int i =  0;  i  <  m;  i++){
    int u , v; std::cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
}
