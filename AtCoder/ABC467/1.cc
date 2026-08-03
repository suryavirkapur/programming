#include <bits/stdc++.h>
using namespace std;

int main() {
  long long H, W;
  cin >> H >> W;

  if (W * 10000 >= 25 * H * H)
    cout << "Yes\n";
  else
    cout << "No\n";
}
