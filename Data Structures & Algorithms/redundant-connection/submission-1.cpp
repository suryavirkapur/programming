#include "dsa/dsa.hpp"
using namespace std;

class Solution {
vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] =  find(parent[x]);
        }
        return parent[x];
    }

    bool unite (int a, int b){
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false;
        parent[pb] = pa;
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n  = edges.size();
        parent.resize(n +1);

        for (int i = 1; i <= n; i++)parent[i] = i;
        for (auto& edge : edges){
            int u = edge[0]; int v = edge[1];
            if (!unite(u,v)) {
                return edge;
            }
        }
        return {};
    }
};

int main() { return 0; }
