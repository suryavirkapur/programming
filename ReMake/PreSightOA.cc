#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::min;
using std::string;
using std::unordered_map;
using std::vector;

void solve() {
  vector<string> words = {"blue",   "red",  "yellow", "green",
                          "yellow", "blue", "x",      "red"};

  int min_dst = INT_MAX;
  unordered_map<string, int> wordMap;

  for (int i = 0; i < words.size(); i++) {
    string currWord = words[i];

    if (wordMap.count(currWord) > 0) {
      min_dst = min(min_dst, i - wordMap[currWord] - 1);
    }

    wordMap[currWord] = i;
  }

  cout << min_dst << "\n";
}

int main() {
  solve();
  return 0;
}
