class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) return false;
       // we have to check for two things 

       // whether all nodes are connected from any one node 

       // while also checking if everything is acyclic 

       // we can do this easily hopefully 
        vector<vector<int>> adjList(n);
        vector<int> isVisited(n);
       for (const auto &edge : edges) {
                int to = edge[0];
                int from = edge[1];

                adjList[to].push_back(from);
                adjList[from].push_back(to);
       }

        queue<int> q;

        q.push(0);
        isVisited[0] = 1;

        while(!q.empty()) {
            int node = q.front(); q.pop();

            for (int ngh  :  adjList[node]) {
                if(!isVisited[ngh]) {
                    isVisited[ngh] = 1;
                    q.push(ngh);
                }
            }
        }

       for (int i : isVisited) {
            if (i !=1) return false;
       }
        return true;
    }

    
};
