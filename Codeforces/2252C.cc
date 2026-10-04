#include <algorithm>
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

struct SegmentTree {
  int n;

  vi cnt;
  vi64 sum;

  SegmentTree(int n) : n(n), cnt(4 * n), sum(4 * n) {}

  void add(int node, int l, int r, int pos, i64 val) {

    if (l == r) {
      cnt[node]++;
      sum[node] += val;
      return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
      add(node * 2, l, mid, pos, val);
    else
      add(node * 2 + 1, mid + 1, r, pos, val);

    cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
  }

  void add(int pos, i64 val) { add(1, 0, n - 1, pos, val); }

  int query(int node, int l, int r, i64 need) {

    if (need <= 0)
      return 0;

    if (l == r) {
      return (need + l - 1) / l;
    }

    int mid = (l + r) / 2;
    int right = node * 2 + 1;

    if (sum[right] >= need)
      return query(right, mid + 1, r, need);

    return cnt[right] + query(node * 2, l, mid, need - sum[right]);
  }

  int query(i64 need) {

    if (sum[1] < need)
      return -1;

    return query(1, 0, n - 1, need);
  }
};

void solve() {

  int n, m;
  cin >> n >> m;

  vi64 v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  vector<vi64> a(n, vi64(m));
  vi64 values;

  values.reserve(1LL * n * m + 1);
  values.push_back(0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      values.push_back(a[i][j]);
    }
  }

  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());

  int sz = values.size();

  vi cnt(4 * sz, 0);
  vi64 sum(4 * sz, 0);

  auto add = [&](auto &&self, int node, int l, int r, int pos,
                 i64 val) -> void {
    if (l == r) {
      cnt[node]++;
      sum[node] += val;
      return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
      self(self, node * 2, l, mid, pos, val);
    else
      self(self, node * 2 + 1, mid + 1, r, pos, val);

    cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
  };

  auto query = [&](auto &&self, int node, int l, int r, i64 need) -> int {
    if (need <= 0)
      return 0;

    if (l == r) {
      i64 damage = values[l];
      return (need + damage - 1) / damage;
    }

    int mid = (l + r) / 2;
    int right = node * 2 + 1;

    if (sum[right] >= need)
      return self(self, right, mid + 1, r, need);

    return cnt[right] + self(self, node * 2, l, mid, need - sum[right]);
  };

  int ans = m;

  for (int i = n - 1; i >= 0; i--) {

    for (int j = 0; j < m; j++) {
      int pos = std::lower_bound(values.begin(), values.end(), a[i][j]) -
                values.begin();

      add(add, 1, 0, sz - 1, pos, a[i][j]);
    }

    if (sum[1] < v[i])
      continue;

    int operations = query(query, 1, 0, sz - 1, v[i]);

    ans = std::min(ans, operations);
  }

  cout << ans << "\n";
}

int main(int argc, char *argv[]) {

  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
