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
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> addrMap;
        int right = 0;
        while (head){
            addrMap[right] = head;
            head = head->next;
            right++;
        }
        right--;
        int left = 0;
        while (left < right){
            addrMap[left]->next = addrMap[right];
            left++;
            addrMap[right]->next = addrMap[left];
            right--;
        }
        addrMap[left]->next = nullptr;
    }
};
