// Link: https://leetcode.com/problems/clone-graph/
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cin, std::cout, std::endl, std::string, std::vector;
using std::unordered_map, std::unordered_set;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val = 0, vector<Node*> _neighbors = {})
        : val(_val), neighbors(std::move(_neighbors)) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        auto it = visited_.find(node);
        if (it != visited_.end()) return it->second;

        auto clone = std::make_unique<Node>(node->val);
        Node* result = clone.get();
        visited_[node] = result;
        clones_.push_back(std::move(clone));

        for (Node* neighbor : node->neighbors)
            result->neighbors.push_back(cloneGraph(neighbor));

        return result;
    }

    void clear() { visited_.clear(); clones_.clear(); }

private:
    unordered_map<Node*, Node*> visited_;
    std::vector<std::unique_ptr<Node>> clones_;
};

struct Graph {
    std::vector<std::unique_ptr<Node>> pool;
    Node* head = nullptr;
};

Graph buildGraph(const vector<vector<int>>& adj) {
    if (adj.empty()) return {};
    int n = static_cast<int>(adj.size());
    Graph g;
    for (int i = 1; i <= n; ++i) g.pool.push_back(std::make_unique<Node>(i));
    for (int i = 0; i < n; ++i)
        for (int neighborVal : adj[static_cast<size_t>(i)])
            g.pool[static_cast<size_t>(i)]->neighbors.push_back(
                g.pool[static_cast<size_t>(neighborVal - 1)].get());
    g.head = g.pool[0].get();
    return g;
}

bool compareGraphs(Node* n1, Node* n2, unordered_set<int>& visited_vals) {
    if (!n1 && !n2) return true;
    if (!n1 || !n2) return false;
    if (n1->val != n2->val) return false;
    if (visited_vals.contains(n1->val)) return true;

    visited_vals.insert(n1->val);
    if (n1->neighbors.size() != n2->neighbors.size()) return false;
    if (n1 == n2) return false;

    for (size_t i = 0; i < n1->neighbors.size(); ++i)
        if (!compareGraphs(n1->neighbors[i], n2->neighbors[i], visited_vals))
            return false;
    return true;
}

int main() {
    Solution sol;

    auto g1 = buildGraph({{2,4},{1,3},{2,4},{1,3}});
    Node* cloned1 = sol.cloneGraph(g1.head);
    unordered_set<int> visited_vals;
    bool pass1 = compareGraphs(g1.head, cloned1, visited_vals);
    cout << "Test Case 1: " << (pass1 ? "PASSED" : "FAILED") << endl;

    auto g2 = buildGraph({{}});
    Solution sol2;
    Node* cloned2 = sol2.cloneGraph(g2.head);
    visited_vals.clear();
    bool pass2 = compareGraphs(g2.head, cloned2, visited_vals);
    cout << "Test Case 2: " << (pass2 ? "PASSED" : "FAILED") << endl;

    auto g3 = buildGraph({});
    Solution sol3;
    Node* cloned3 = sol3.cloneGraph(g3.head);
    bool pass3 = (cloned3 == nullptr);
    cout << "Test Case 3: " << (pass3 ? "PASSED" : "FAILED") << endl;

    if (pass1 && pass2 && pass3) cout << "\nAll test cases PASSED!" << endl;
    else cout << "\nSome test cases FAILED." << endl;
}
