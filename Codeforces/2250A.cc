
#include <algorithm>
#include <climits>
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
  vi64 arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (n % 2 == 1) {
    cout << "NO\n";
    return;
  }

  i64 odd = LLONG_MAX, even = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      odd = std::min(odd, arr[i]);
    else
      even = std::max(even, arr[i]);
  }

  if (even + 1 < odd)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
