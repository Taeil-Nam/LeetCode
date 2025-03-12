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
    /* Iteration */
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    /* Recursion */
    // ListNode* reverseList(ListNode* head) {
    //     return go(nullptr, head);
    // }

    // ListNode* go(ListNode* prev, ListNode* node){
    //     if (node == nullptr){
    //         return prev;
    //     }
    //     ListNode* head = go(node, node->next);
    //     node->next = prev;
    //     return head;
    // }
};