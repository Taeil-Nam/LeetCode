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
        if (!root)
            return true;
        return helper(root);
    }

    bool helper(TreeNode* node){
        if (!node)
            return true;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        if (abs(leftDepth - rightDepth) > 1)
            return false;
        return helper(node->left) && helper(node->right);
    }

    int getDepth(TreeNode* node){
        if (!node)
            return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
};