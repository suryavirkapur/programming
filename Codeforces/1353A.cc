#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  i64 n, k;
  cin >> n >> k;

  if (n == 1)
    cout << "0\n";
  if (n == 2)
    cout << k << "\n";
  if (n == 3)
    cout << 2 * k << "\n";
  if (n > 3)
    cout << 2 * k << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
