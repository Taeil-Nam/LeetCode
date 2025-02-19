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
        bool isCarry = false;
        ListNode dummy;
        ListNode* node = &dummy;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                sum = l2->val;
                l2 = l2->next;
            }
            else if (l2 == nullptr){
                sum = l1->val;
                l1 = l1->next;
            }
            else{
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            if (isCarry) sum++;
            if (sum >= 10){
                isCarry = true;
                sum = sum % 10;
            }
            else isCarry = false;
            node->next = new ListNode(sum);
            node = node->next;
        }
        if (isCarry)
            node->next = new ListNode(1);
        return dummy.next;
    }
};
