#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {
  std::string s;
  cin >> s;

  size_t n = s.size();
  if (n == 2) {
    cout << s << "\n";
    return;
  }
  std::string res = "";
  res += s[0];
  for (size_t i = 1; i < n - 1; i += 2) {
    res += s[i];
  }
  res += s[n - 1];

  cout << res << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
