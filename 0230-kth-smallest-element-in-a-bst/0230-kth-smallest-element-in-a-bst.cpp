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
private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        for (int i = 1; i < k; i++) {
            pq.pop();
        }
        return pq.top();
    }

    void dfs(TreeNode* node) {
        if (!node)
            return;
        pq.push(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};