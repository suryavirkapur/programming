#include <algorithm>
#include <climits>
#include <ios>
#include <iostream>
#include <vector>

using std::cout, std::cin, std::ios_base;
using std::min;
using std::vector;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  vector<int> B(N - 1);

  for (int &x : A)
    cin >> x;
  for (int &x : B)
    cin >> x;

  ll res = INT_MAX;

  for (int f = 0; f < M; f++) {
    int curr = f;
    ll ops = (curr - A[0] + M) % M;

    for (int i = 0; i < N - 1; i++) {
      int nxt = (B[i] - curr + M) % M;

      ops += (nxt - A[i + 1] + M) % M;
      curr = nxt;
    }

    res = min(res, ops);
  }

  cout << res << '\n';
}
