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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        int cnt = 0;
        ListNode* node = head;
        while (node){
            size++;
            node = node->next;
        }
        if (size - n == 0)
            return head->next;

        node = head;
        while (node){
            cnt++;
            if (size - cnt == n){
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return head;
    }
};