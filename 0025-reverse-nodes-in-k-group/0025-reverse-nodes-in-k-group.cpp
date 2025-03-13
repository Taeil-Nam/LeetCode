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
        ListNode dummy;
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while (true){
            ListNode* kth = getKth(groupPrev, k);
            if (!kth)
                break;
            ListNode* prev = kth->next;
            ListNode* node = groupPrev->next;
            while (node != kth->next){
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy.next;
    }

    ListNode* getKth(ListNode* node, int k){
        while (node && k){
            node = node->next;
            k--;
        }
        return node;
    }
};