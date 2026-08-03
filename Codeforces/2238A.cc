#include <algorithm>
#include <cstdint>
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
  i64 c;
  cin >> n >> c;

  i64 res = 0;

  i64 sumA = 0;
  i64 sumB = 0;

  vi64 a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sumA += a[i];
  }

  vi64 b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sumB += b[i];
  }

  if (sumA < sumB) {
    cout << "-1\n";
    return;
  }

  bool orderChanged = false;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      orderChanged = true;
      break;
    }
  }

  if (orderChanged) {
    res = INT64_MAX;
  } else {
    res = sumA - sumB;
  }

  vi64 a_copy = a;
  vi64 b_copy = b;

  std::sort(a_copy.begin(), a_copy.end());
  std::sort(b_copy.begin(), b_copy.end());

  i64 res2 = c;
  bool orderChanged2 = false;

  for (int i = 0; i < n; i++) {
    if (a_copy[i] < b_copy[i]) {
      orderChanged2 = true;
      break;
    }

    res2 += a_copy[i] - b_copy[i];
  }

  if (orderChanged2) {
    res2 = INT64_MAX;
  }

  i64 ans = std::min(res, res2);

  if (ans == INT64_MAX) {
    cout << "-1\n";
    return;
  }

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
