#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "Welcome to GfG!";
  string sub = "to";

  // Checking if sub is present in s
  size_t res = s.find(sub);
  if (res != string::npos)
    cout << "Found: " << res << "\n";
  else
    cout << sub << " NOT found.\n";

  return 0;
}
