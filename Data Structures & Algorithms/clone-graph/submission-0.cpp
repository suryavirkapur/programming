#include "dsa/dsa.hpp"
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         unordered_map<Node*, Node*> clones;
//         queue<Node*> q;
//         q.push(node);
//         while (!q.empty()) {
//             Node* currNode = q.front(); q.pop();
//             auto it = clones.find(currNode);
//             Node* newNode = new Node(currNode->val);
//             if (it == clones.end()) {
//                 clones.insert({currNode, newNode})
//             }
//             for (Node* neighbor : currNode->neighbors) {
//                 q.push(neighbor);
//             }
//         }
//         return newNode;
//     }
// };


class Solution {
public:
    unordered_map<Node*, Node*> clones;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return dfs(node);
    }

    Node* dfs(Node* node) {
        if (clones.count(node)) return clones[node];

        Node* copy = new Node(node->val);
        clones[node] =  copy;
        for (auto nei : node->neighbors) 
           copy->neighbors.push_back(dfs(nei));
        return copy;
    }
};

int main() { return 0; }
