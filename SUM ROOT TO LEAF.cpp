// SUM ROOT TO LEAF

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
    int sumNumbers(TreeNode* root) {
        return CurrSum(root, 0);
    }

private:
    int CurrSum(TreeNode* node, int currentSum) {
        if (node == NULL) {
            return 0;
        }

        
        int newSum = currentSum * 10 + node->val;

        // leaf node, return the number formed
        if (node->left == NULL && node->right == NULL) {
            return newSum;
        }

        int leftSum = CurrSum(node->left, newSum);
        int rightSum = CurrSum(node->right, newSum);

        return leftSum + rightSum;
    }
};
