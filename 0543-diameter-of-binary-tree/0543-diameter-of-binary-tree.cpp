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
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return res;
    }

    int getDepth(TreeNode* node){
        if (!node)
            return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        int diameter = leftDepth + rightDepth;
        res = max(res, diameter);
        return 1 + max(leftDepth, rightDepth);
    }
};