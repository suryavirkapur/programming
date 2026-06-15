#include <iostream>
#include <vector>


using std::vector;
using std::cin;
using std::cout;

using vi = vector<int>;
using vll = vector<long long>;


int main(int argc, char* argv[]) {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (k == 1){
            bool sorted = true;
            for (int i = 1; i < n; ++i) {
               if ( a[i] < a[i-1]) {
                   sorted = false;
                   break;
               }
            }
            cout << (sorted ? "YES" : "NO") << "\n";
        } else {
            cout << "YES\n";
        }

    }

    return 0;
}
