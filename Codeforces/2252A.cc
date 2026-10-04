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

  vi a(n);
  vi freq(1001, 0);

  i64 sum = 0;

  int mx = 0;
  int val = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];

    sum += a[i];
    freq[a[i]]++;

    if (freq[a[i]] > mx) {
      mx = freq[a[i]];
      val = a[i];
    }
  }

  int other = n - mx;

  if (mx <= other + 1) {
    cout << sum << "\n";
    return;
  }

  int unused = mx - (other + 2);

  cout << sum - 1LL * unused * val << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
