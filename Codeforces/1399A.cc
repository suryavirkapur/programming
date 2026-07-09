#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  i64 n;
  cin >> n;

  vi a(n);
  cin >> a[0];

  if (n == 1) {
    cout << "YES\n";
    return;
  }

  for (i64 i = 1; i < n; ++i) {
    cin >> a[i];
  }
  std::sort(a.begin(), a.end());

  for (i64 i = 1; i < n; ++i) {
    if (abs(a[i] - a[i - 1]) > 1) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}
int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
