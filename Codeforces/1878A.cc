#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

using i64 = long long;
using vi = vector<int>;
using vll = vector<long long>;


int main(int argc, char* argv[]) {
    int t; cin >> t;
    while (t--) {
        bool found = false;
        int n, k; cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] == k) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}
