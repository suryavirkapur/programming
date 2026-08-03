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

struct FenwickTree {
    int n;
    vi tree;

    FenwickTree(int n): n(n), tree(n+1, 0) {}

    void add(int i, int d) {
        for (; i <=n; i += i & -i) tree[i] += d;
    }

    int query(int i) {
        int sum = 0;
        for (; i <=n; i += i & -i) sum += tree[i];
        return sum;
    }
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> vec(N, 0);
    vector<int> frq(Q+1, 0);
    frq[0] = N;
    FenwickTree bit(Q+1);
    bit.add(1,N);
    int offset = 0;
    for (int i = 0; i < Q; i++) {
        int T, V;
        cin >> T >> V;
        if (T == 1) {
        V--;
        int oval = vec[V];
        frq[oval]--;
        bit.add(oval + 1, -1);
        vec[V]++;
        int nval = vec[V];
        frq[nval]++;
        bit.add(nval + 1,  1);

        if (frq[offset] == 0) offset++;
        }
        else if (T == 2){
        int y = V;
        int need = y + offset;

        if (need > Q) {
            cout << 0 << "\n";
        }
        else {
            int cnt = N - bit.query(need);
            cout << cnt << "\n";
        }
        }
    }    
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
