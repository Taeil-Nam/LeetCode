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

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr) { return true; }
        if (p == nullptr || q == nullptr || p->val != q->val ) { return false; }
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

// Time complexity = O(n)
// Space complexity = O(n)

/*
Approch

1. 두 노드가 nullptr인 경우, true를 반환한다. (동일하게 nullptr 이니깐)
2. 두 노드 중 하나만 nullptr이거나(노드의 위치가 맞지 않음), 두 노드의 값이 다른 경우 false를 반환한다.
3. 현재 노드의 left, right에 대해 1번 과정부터 재귀를 수행하고, 둘 다 true일 경우에만 true를 반환한다.

최종적으로, 모든 조건이 true가 되었을 경우에만(모든 노드의 위치와 값이 같은 경우에만) true를 반환한다.
*/