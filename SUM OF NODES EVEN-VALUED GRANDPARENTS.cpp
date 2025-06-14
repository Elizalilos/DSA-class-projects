// SUM OF NODES EVEN-VALUED GRANDPARENTS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL) return 0;

        int total = 0;
        vector<TreeNode*> path;  // store ancestors from root to current node
        dfs(root, path, total);
        return total;
    }

private:
    void dfs(TreeNode* node, vector<TreeNode*>& path, int& total) {
        if (node == NULL) return;

        // Check if grandparent exists in path and is even-valued
        if (path.size() >= 2) {
            TreeNode* grandparent = path[path.size() - 2];
            if (grandparent->val % 2 == 0) {
                total += node->val;
            }
        }

        // Add current node to path
        path.push_back(node);

        // Recurse left and right
        dfs(node->left, path, total);
        dfs(node->right, path, total);

        // Backtrack: remove current node before returning
        path.pop_back();
    }
};
