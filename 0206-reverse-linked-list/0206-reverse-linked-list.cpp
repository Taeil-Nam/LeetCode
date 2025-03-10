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
    // Iteration
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prevNode = nullptr;
    //     ListNode* currNode = head;
    //     while (currNode){
    //         ListNode* nextNode = currNode->next;
    //         currNode->next = prevNode;
    //         prevNode = currNode;
    //         currNode = nextNode;
    //     }
    //     return prevNode;
    // }

    // Recursion
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* firstNode = head;
        if (head->next){
            firstNode = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;
        return firstNode;
    }
};