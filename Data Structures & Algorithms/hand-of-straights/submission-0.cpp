#include "dsa/dsa.hpp"
using namespace std;

using vi = vector<int>;
using vvi =  vector<vi>;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int numGroups = 0;
        if (n % groupSize != 0) return false;
        numGroups = n / groupSize;

        sort(hand.begin(), hand.end());
        vvi res(numGroups);

        unordered_map<int, int> frq;
        for (int i = 0; i < n; i++) {
            frq[hand[i]]++;
        }
        
        for (int g = 0; g < numGroups; g++) {
            for (int i  = 0; i < n; i++) {
                if (res[g].size() == groupSize) break;
                
                if (!res[g].empty() && frq.count(hand[i]) >= 1 && hand[i] == res[g].back() + 1) {
                    res[g].push_back(hand[i]);
                    frq[hand[i]]--;
                    if (frq[hand[i]] == 0) frq.erase(hand[i]);
                } else if (res[g].empty() && frq.count(hand[i]) >= 1) {
                    res[g].push_back(hand[i]);
                    frq[hand[i]]--;
                    if (frq[hand[i]] == 0) frq.erase(hand[i]);
                } 
            }
        }

        for (int g = 0; g < numGroups; g++) {
            if (res[g].size() != groupSize) return false;

            for (auto  i : res[g]) cout << i << " ";
            cout << "\n";
        }

        return true;
    }
};

int main() { return 0; }
