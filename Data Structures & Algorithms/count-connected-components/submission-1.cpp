#include "dsa/dsa.hpp"
using namespace std;

class Solution {
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
    } 

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false;
        parent[pb] =  pa;
        return true;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
            parent.resize(n);

            for (int i = 0; i  < n; i++){
                parent[i] = i;
            }

            for (auto edge : edges){
                int u = edge[0];
                int v = edge[1];

                if (unite(u,v)) {
                    components--;
                }
            }
            return components;
    }
};

int main() { return 0; }
