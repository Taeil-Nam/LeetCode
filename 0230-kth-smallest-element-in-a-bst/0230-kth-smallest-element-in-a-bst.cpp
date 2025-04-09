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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorderTraversal(root, v);
        return v[k - 1];
    }

    void inorderTraversal(TreeNode* node, vector<int>& v) {
        if (!node)
            return;
        inorderTraversal(node->left, v);
        v.push_back(node->val);
        inorderTraversal(node->right, v);
    }
};