
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

using i64 = long long;
using vi = vector<i64>;
using vi64 = vector<i64>;

void solve() {
  i64 n, k;
  cin >> n >> k;

  if (n - k == 1) {
    cout << -1 << '\n';
    return;
  }

  i64 r = n - k;

  i64 zeros = n / 2;
  i64 ones = n - zeros;

  char start;

  i64 zeror;
  i64 oner;

  if (r % 2 == 0) {
    start = '0';
    zeror = r / 2;
    oner = r / 2;
  } else {
    if (ones > zeros) {
      start = '1';
      oner = (r + 1) / 2;
      zeror = r / 2;
    } else {
      start = '0';
      zeror = (r + 1) / 2;
      oner = r / 2;
    }
  }

  vi64 zerol(zeror, 1);
  vi64 onel(oner, 1);
  zerol[0] += zeros - zeror;
  onel[0] += ones - oner;

  string res = "";

  i64 zeroIndex = 0, oneIndex = 0;
  char curr = start;

  for (i64 run = 0; run < r; run++) {
    if (curr == '0') {
      res += string(zerol[zeroIndex++], '0');
      curr = '1';
    } else {
      res += string(onel[oneIndex++], '1');
      curr = '0';
    }
  }

  cout << res << '\n';
}

int main() {
  i64 t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
