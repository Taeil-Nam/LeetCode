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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (ListNode* node : lists){
            while (node){
                v.push_back(node->val);
                node = node->next;
            }
        }
        sort(v.begin(), v.end());

        ListNode dummy;
        ListNode* node = &dummy;
        for (int num : v){
            node->next = new ListNode(num);
            node = node->next;
        }
        return dummy.next;
    }
};