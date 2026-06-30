#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using int64 = long long;
using vi = vector<int>;
using vi64 = vector<int64>;

void solve() {
  int64 x;
  cin >> x;

  int64 p = 1;
  int64 temp = x;

  while (temp > 0) {
    p *= 10;
    temp /= 10;
  }

  int64 y = p + 1;
  cout << y << '\n';
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
