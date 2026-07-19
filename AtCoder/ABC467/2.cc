#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long X = 10000;
  long long Y = 10000;
  while (N--) {
    long A;
    long B;
    string C;
    cin >> A >> B >> C;

    if (C == "take") {
      X -= A;
    }

    if (C == "keep") {
      X -= B;
    }

    Y -= A;
  }

  cout << Y - X << "\n";
}
