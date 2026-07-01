#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

using int64 = long long;
using vi = vector<int>;
using vi64 = vector<int64>;

void solve() {
  int n;
  cin >> n;

  vi64 a(n), b(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 1; i < n; i++)
    a[i] += a[i - 1];
  for (int i = 1; i < n; i++)
    b[i] += b[i - 1];

  bool is = true;
  for (int i = 0; i < n; i++)
    if (a[i] > b[i])
      is = 0;

  if (is)
    cout << "YES\n";
  else
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
