#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  int a, b;
  cin >> a;
  cin >> b;

  if (a % b == 0 || b % a == 0) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
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
