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

// //     if root is empty:
//         return subRoot is also empty

//     if tree rooted at root is identical to subRoot:
//         return true

//     otherwise:
//         check if subRoot exists inside root's left subtree
//         OR
//         check if subRoot exists inside root's right subtree
class Solution {
   public:
    bool same(TreeNode* b, TreeNode* a) {
        if (!b || !a) return a == b;
        return a->val == b->val && same(a->left, b->left) && same(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return subRoot == nullptr;

        if (same(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() { return 0; }
