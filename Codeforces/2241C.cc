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
  int64 n;
  string s;
  cin >> n >> s;
  int64 c = 0;
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1])
      c++;
  if (c == 1)
    cout << "2\n";
  else
    cout << "1\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
