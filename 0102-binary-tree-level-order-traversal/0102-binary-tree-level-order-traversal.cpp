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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()){
            vector<int> nodes;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if (!node) continue;
                nodes.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if (nodes.size() > 0)
                res.push_back(nodes);
        }
        return res;
    }
};