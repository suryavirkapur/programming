#include <bits/stdc++.h>

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

void solve() {
    string s; cin >>  s; int n = sz(s);

    int frq[26] = {0};
    int max_frq = 0;
    char max_char = 'a';

    for (char c : s){
        frq[c - 'a']++;
        if (frq[c - 'a'] > max_frq) {
            max_frq = frq[c - 'a'];
            max_char = c;
        }
    }

    if (max_frq > (n+1)/ 2) {
        cout << "No\n"; return;
    }

    cout << "Yes\n";
    string res(n, ' ');
    int ix = 0;

    while (frq[max_char - 'a'] > 0) {
        res[ix] = max_char;
        ix += 2;
        frq[max_char-'a']--;
    }

    if (ix >= n) ix = 1;
    
    for (int i = 0; i < 26; i++) {
        while (frq[i] > 0) {
            res[ix] = 'a' + i;
            ix += 2;
            if (ix >= n) ix = 1; frq[i]--;
        }    
    }

    cout << res << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t; // Comment out if the problem only has one testcase (e.g., most CSES problems)
    
    while (t--) {
        solve();
    }

    return 0;
}
