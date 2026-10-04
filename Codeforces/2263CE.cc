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
  int n;
  cin >> n;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> diff(n + 2, 0);

  for (int k = 1; k <= n; k++) {
    i64 L = 1LL * a[k] * k;
    if (L >= n)
      continue;
    i64 R = 1LL * (a[k] + 1) * k - 1;
    if (R >= n)
      R = n - 1;
    if (L <= R) {
      diff[L]++;
      diff[R + 1]--;
    }
  }

  vi ans;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += diff[i];
    if (cur == 0) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
  }
  if (ans.empty())
    cout << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
