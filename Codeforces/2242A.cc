#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  int k;
  cin >> k;
  vi64 a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }

  if (k == 1) {
    if (a[0] < 3)
      cout << "NO\n";
    else
      cout << "YES\n";
    return;
  }

  if (k >= 2) {
    int cnt = 0;
    bool has3 = false;

    for (int i = 0; i < k; i++) {
      if (a[i] >= 2)
        cnt++;
      if (a[i] >= 3)
        has3 = true;
    }
    if (has3 || cnt >= 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
