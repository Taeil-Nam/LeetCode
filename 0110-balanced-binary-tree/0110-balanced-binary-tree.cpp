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
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root);
    }

    bool checkBalanced(TreeNode* node) {
        if (!node)
            return true;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        if (abs(leftDepth - rightDepth) > 1)
            return false;
        return checkBalanced(node->left) && checkBalanced(node->right);
    }

    int maxDepth(TreeNode* node) {
        if (!node)
            return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }
};