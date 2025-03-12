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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* node = &dummy;
        bool carry = false;
        int sum = 0;
        while (l1 || l2){
            if (!l1){
                sum = l2->val;
                l2 = l2->next;
            }
            else if (!l2){
                sum = l1->val;
                l1 = l1->next;
            }
            else{
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            if (carry) sum++;
            if (sum >= 10){
                carry = true;
                sum %= 10;
            }
            else
                carry = false;
            node->next = new ListNode(sum);
            node = node->next;
        }
        if (carry)
            node->next = new ListNode(1);
        return dummy.next;
    }
};