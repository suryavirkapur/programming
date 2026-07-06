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
  int n;
  cin >> n;

  vi arr(n + 1);
  vi p1(n + 1, 0), p2(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];

    p1[i] = p1[i - 1];
    p2[i] = p2[i - 1];

    if (arr[i] == 1) {
      p1[i]++;
      p2[i]++;
    } else if (arr[i] == 2) {
      p1[i]--;
      p2[i]++;
    } else {
      p1[i]--;
      p2[i]--;
    }
  }

  int mn = INT_MAX;

  for (int r = 2; r <= n - 1; r++) {
    int l = r - 1;

    if (p1[l] >= 0)
      mn = std::min(mn, p2[l]);

    if (mn <= p2[r]) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
