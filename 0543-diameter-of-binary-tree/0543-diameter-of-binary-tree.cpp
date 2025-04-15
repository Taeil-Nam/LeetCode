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
        maxDepth(root);
        return res;
    }

    int maxDepth(TreeNode* node) {
        if (!node)
            return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        res = max(res, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};