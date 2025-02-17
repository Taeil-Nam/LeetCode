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
        ListNode* node = head;
        while (node){
            size++;
            node = node->next;
        }

        ListNode dummy;
        ListNode* prev = &dummy;
        prev->next = head;
        node = head;
        int cnt = 0;
        while (cnt < size - n){
            prev = node;
            node = node->next;
            cnt++;
        }
        prev->next = node->next;
        delete node;
        if (size - n == 0)
            head = prev->next;

        return head;
    }
};
