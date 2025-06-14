// RECOVER BST

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
    void recoverTree(TreeNode* root) {
        vector<int> values;
        // Step 1: Store inorder traversal (this will have swapped values)
        getInorder(root, values);

        // Step 2: Sort the values
        sort(values.begin(), values.end());

        // Step 3: Put the values back in order
        int index = 0;
        restoreTree(root, values, index);
    }

    // In-order traversal to collect values
    void getInorder(TreeNode* node, vector<int>& values) {
        if (!node) return;
        getInorder(node->left, values);
        values.push_back(node->val);
        getInorder(node->right, values);
    }

    // In-order traversal to write back sorted values
    void restoreTree(TreeNode* node, vector<int>& values, int& index) {
        if (!node) return;
        restoreTree(node->left, values, index);
        node->val = values[index++];
        restoreTree(node->right, values, index);
    }
};
