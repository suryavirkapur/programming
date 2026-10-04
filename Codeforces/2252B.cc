#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

void solve() {

  int n;
  cin >> n;

  string s;
  cin >> s;

  int zero = 0;
  int one = 0;

  for (char c : s) {
    if (c == '0')
      zero++;
    else
      one++;
  }

  int totalDiff = zero - one;

  if (totalDiff < -2 || totalDiff > 2) {
    cout << -1 << "\n";
    return;
  }

  const int neg = -1e9;

  vector<vector<int>> dp(2, vector<int>(3, neg));

  for (char c : s) {

    int x = c - '0';

    vector<vector<int>> next = dp;

    int diff = (x == 0 ? 1 : -1);

    next[x][diff + 1] = 1;

    for (int last = 0; last < 2; last++) {
      for (int d = -1; d <= 1; d++) {

        if (dp[last][d + 1] == neg)
          continue;

        if (last == x)
          continue;

        int newDiff = d + diff;

        if (newDiff < -1 || newDiff > 1)
          continue;

        next[x][newDiff + 1] =
            std::max(next[x][newDiff + 1], dp[last][d + 1] + 1);
      }
    }

    dp = next;
  }

  int longest = 0;

  for (int last = 0; last < 2; last++) {
    for (int remainingDiff = -1; remainingDiff <= 1; remainingDiff++) {

      int deletedDiff = totalDiff - remainingDiff;

      if (deletedDiff < -1 || deletedDiff > 1)
        continue;

      longest = std::max(longest, dp[last][remainingDiff + 1]);
    }
  }

  cout << n - longest << "\n";
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
