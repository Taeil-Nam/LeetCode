/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v(k);
        ListNode* node = head;
        while (true){
            if (checkNode(node, k, v) == false)
                break;
            for (int i = k - 1; i >= 0; i--){
                node->val = v[i];
                node = node->next;
            }
        }
        return head;
    }

    bool checkNode(ListNode* head, int k, vector<int>& v){
        for (int i = 0; i < k; i++){
            if (head == nullptr)
                return false;
            v[i] = head->val;
            head = head->next;
        }
        return true;
    }
};