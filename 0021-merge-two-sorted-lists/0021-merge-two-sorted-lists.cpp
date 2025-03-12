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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* node = &dummy;
        while (list1 && list2){
            if (list1->val <= list2->val){
                ListNode* newNode = new ListNode(list1->val);
                node->next = newNode;
                list1 = list1->next;
            }
            else{
                ListNode* newNode = new ListNode(list2->val);
                node->next = newNode;
                list2 = list2->next;
            }
            node = node->next;
        }
        while (list1){
            ListNode* newNode = new ListNode(list1->val);
            node->next = newNode;
            node = node->next;
            list1 = list1->next;
        }
        while (list2){
            ListNode* newNode = new ListNode(list2->val);
            node->next = newNode;
            node = node->next;
            list2 = list2->next;
        }
        node->next = nullptr;
        
        return dummy.next;
    }
};