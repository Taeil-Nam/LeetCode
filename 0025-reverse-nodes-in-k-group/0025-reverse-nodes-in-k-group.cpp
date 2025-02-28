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
        int arr[k];
        ListNode* node = head;
        while (true){
            if (checkNode(node, k, arr) == false)
                break;
            for (int i = k - 1; i >= 0; i--){
                node->val = arr[i];
                node = node->next;
            }
        }
        return head;
    }

    bool checkNode(ListNode* head, int k, int* arr){
        for (int cnt = 0; cnt < k; cnt++){
            if (head == nullptr)
                return false;
            arr[cnt] = head->val;
            head = head->next;
        }
        return true;
    }
};