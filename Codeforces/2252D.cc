#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {

  int n;
  cin >> n;

  vi64 a(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  vi64 d(n - 1);

  for (int i = 0; i < n - 1; i++)
    d[i] = a[i + 1] - a[i];

  int l = 0;

  while (l < n - 1) {

    int r = l;

    while (r + 1 < n - 1 && ((d[r] & 1LL) == (d[r + 1] & 1LL)))
      r++;

    sort(d.begin() + l, d.begin() + r + 1);

    l = r + 1;
  }

  cout << a[0] << " ";

  i64 current = a[0];

  for (int i = 0; i < n - 1; i++) {
    current += d[i];

    cout << current;

    if (i + 1 < n - 1)
      cout << " ";
  }

  cout << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
