//All Nodes Distances
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
    // Step 1: Map child to parent
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->left) {
                parentTrack[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentTrack[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;  // child -> parent
        map<TreeNode*, bool> visited;
        vector<int> res;

        // Map all parent pointers
        mapParents(root, parentTrack);

        // Step 2: BFS from target
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited[target] = true;

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist == k) {
                res.push_back(curr->val);
            }

            // Stop adding more nodes once we've hit distance k
            if (dist > k) break;

            // Try left
            if (curr->left && !visited[curr->left]) {
                q.push({curr->left, dist + 1});
                visited[curr->left] = true;
            }

            // Try right
            if (curr->right && !visited[curr->right]) {
                q.push({curr->right, dist + 1});
                visited[curr->right] = true;
            }

            // Try parent
            if (parentTrack[curr] && !visited[parentTrack[curr]]) {
                q.push({parentTrack[curr], dist + 1});
                visited[parentTrack[curr]] = true;
            }
        }

        return res;
    }
};
