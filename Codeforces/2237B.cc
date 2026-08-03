#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::cin;
using std::cout;

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

// struct Element {
//     long long a;
//     int original_index;
// };
void solve() {

    int n; cin >> n;
    vll a(n);
    //vector<Element> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        //elements[i] = {a[i], i};
    }
    // std::sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
    //     return a.a < b.a;
    // });
    vll b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    std::set<ll> emty;
    for (int i = 0; i < n; i++) {
        emty.insert(i);
    }

    vll t(n);

    for (int i = 0; i < n; i++) {
        int x = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        auto it = emty.lower_bound(x);

        if (it == emty.end()) {
            cout << "-1\n";
            return;
        }
        t[i] = *it;
        emty.erase(it);

    }
    ll ops = 0;
    for (int i =0; i < n; i++) for (int j = i + 1; j < n; j++) {
        if (t[i] > t[j]) ops++;
    }
    cout << ops << "\n";

}

int main(int argc, char* argv[]) {
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
