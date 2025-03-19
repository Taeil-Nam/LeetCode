/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> us;
        while (headA || headB){
            if (headA){
                if (us.count(headA)) return headA;
                us.insert(headA);
                headA = headA->next;
            }
            if (headB){
                if (us.count(headB)) return headB;
                us.insert(headB);
                headB = headB->next;
            }
        }
        return nullptr;
    }
};