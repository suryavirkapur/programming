#include "dsa/dsa.hpp"
using namespace std;

class Solution {
public:
    int curMax = numeric_limits<int>::min();
    int dfs(TreeNode* node){
        if (!node) return 0;

        int val = node->val;

        int l = max(0, dfs(node->left));
        int r = max(0, dfs(node->right));

        int t = max(l,r);
        curMax = max(curMax, l + r + val);

        return val + t;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return curMax;
    }
};

int main() { return 0; }
