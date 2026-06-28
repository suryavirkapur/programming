#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  i64 n, ans = 0;
  cin >> n;
  for (int b = 1; b <= n; b++)
    ans += (n / b) * (n / b);
  cout << ans << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
