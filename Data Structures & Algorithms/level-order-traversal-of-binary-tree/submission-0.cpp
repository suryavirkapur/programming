#include "dsa/dsa.hpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* node, int depth, vector<vector<int>> &res) {
        if (!node) return;
        if (res.size() <= depth) res.push_back(vector<int> ());
        res[depth].push_back(node->val);
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = 0;
        vector<vector<int>> res;
        dfs(root, depth, res);
        return res;
    }
};

int main() { return 0; }
