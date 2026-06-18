#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>> pq;
    int lastStoneWeight(vector<int>& stones) {
        for (int s : stones) {
            pq.push(s);
        }
        while(pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if (y > x) 
            { 
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main() { return 0; }
