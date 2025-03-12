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
        while (l1 && l2){
            int sum = l1->val + l2->val;
            if (carry) sum++;
            if (sum >= 10){
                carry = true;
                sum %= 10;
            }
            else
                carry = false;
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1){
            int sum = l1->val;
            if (carry) sum++;
            if (sum >= 10){
                carry = true;
                sum %= 10;
            }
            else
                carry = false;
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
        }
        while (l2){
            int sum = l2->val;
            if (carry) sum++;
            if (sum >= 10){
                carry = true;
                sum %= 10;
            }
            else
                carry = false;
            node->next = new ListNode(sum);
            node = node->next;
            l2 = l2->next;
        }
        if (carry){
            node->next = new ListNode(1);
        }
        return dummy.next;
    }
};