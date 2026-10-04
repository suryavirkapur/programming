#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  int n, k;
  cin >> n >> k;

  if (k < n || k > 2 * n - 1) {
    cout << -1 << "\n";
    return;
  }

  int m = 2 * n - k;
  vector<vector<int>> A(n, vector<int>(n, 0));

  for (int i = 0; i < m; i++) {
    A[i][i] = i + 1;
  }

  for (int i = m; i < n; i++) {
    A[i][0] = i + 1;
  }

  for (int j = m; j < n; j++) {
    A[0][j] = n + (j - m + 1);
  }

  int cur = 2 * n - m + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] == 0) {
        A[i][j] = cur++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << (j + 1 == n ? '\n' : ' ');
    }
  }
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
