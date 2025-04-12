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
    unordered_map<int, int> indices;
    int preIdx = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder, 0, inorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r)
            return nullptr;
        
        int nodeVal = preorder[preIdx++];
        TreeNode* node = new TreeNode(nodeVal);

        int mid = indices[nodeVal];
        node->left = dfs(preorder, l, mid - 1);
        node->right = dfs(preorder, mid + 1, r);
        return node;
    }
};

/*
preorder = 각 서브트리의 root 노드를 알 수 있음.
inorder = 각 root 노드의 왼쪽, 오른쪽 자식 노드를 알 수 있음.
*/