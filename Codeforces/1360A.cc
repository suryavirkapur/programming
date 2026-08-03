#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  i64 a, b;
  cin >> a >> b;

  if (b > a)
    std::swap(a, b);

  i64 bigSide = std::max(2 * b, a);

  cout << bigSide * bigSide << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
