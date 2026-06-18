#include <iostream>
#include <numeric>
#include <vector>


using std::vector;
using std::cin;
using std::cout;

using vi = vector<int>;
using ll = long long;
using vll = vector<long long>;

void solve() {
    int n; cin >> n;
    vi a(n);
    bool decreasing = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] > a[i - 1]) {
            decreasing = false;
        }
    }

    if (decreasing) {
        ll sum = std::accumulate(a.begin(), a.end(), 0);
        cout << sum << '\n';
        return;
    }
    ll res = 0;

    ll currMin = a[0];
    for (int i  = 0; i < n; i++) {
        currMin = std::min(currMin, (ll)a[i]);
        res += currMin;
    }
    cout << res << '\n';
}

int main(int argc, char* argv[]) {
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
