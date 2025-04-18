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
    TreeNode* invertTree(TreeNode* root) {
        /* DFS */
        // if (!root)
        //     return nullptr;
        // swap(root->left, root->right);
        // invertTree(root->left);
        // invertTree(root->right);
        // return root;

        /* BFS */
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()){
            TreeNode* node = q.front();
            q.pop();
            if (!node) continue;
            swap(node->left, node->right);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};