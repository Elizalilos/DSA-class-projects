// LCA 

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }

  
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, nullptr};
        }

        pair<int, TreeNode*> left = dfs(node->left);
        pair<int, TreeNode*> right = dfs(node->right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        if (leftDepth == rightDepth) {
            //both sides - same depth, current node is LCA
            return {leftDepth + 1, node};
        } else if (leftDepth > rightDepth) {
            return {leftDepth + 1, left.second};
        } else {
            return {rightDepth + 1, right.second};
        }
    }
};
