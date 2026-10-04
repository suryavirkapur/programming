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

  i64 n;
  cin >> n;

  vi arr(n);
  int num0 = 0;
  int num1 = 0;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0)
      num0++;
    if (arr[i] == 1)
      num1++;
  }

  if (num1 >= num0)
    cout << "Bessie";
  else
    cout << "Elsie";
  cout << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
