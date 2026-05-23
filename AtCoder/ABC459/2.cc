#include <bits/stdc++.h>
#include <utility>

using namespace std;

// Type aliases
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

// Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()


string mp = "22233344455566677778889999";

void solve() {
    // Write your solution here
  int n; cin >> n;
  vector<string> vec;

  for (int i = 0; i < n; i++) {
      string temp; cin >> temp;
      vec.pb(temp);
  }
    
    string res;
  for (string s : vec) {
        int f = s[0] - 'a';
        char v = mp[f];
        res.push_back(v);
  }

  cout << res << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
//    cin >> t; // Comment out if the problem only has one testcase (e.g., most CSES problems)
    
    while (t--) {
        solve();
    }

    return 0;
}
