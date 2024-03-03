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
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 0; i < n; i++) // O(n)
        {
            first = first->next;
        }
        if (first == nullptr) // 첫번째 원소를 지우는 경우
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (first->next != nullptr) // O(n)
        {
            first = first->next;
            second = second->next;
        }
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;
        return head;
    }
};

/*
Approch
[Variables]
- first = n만큼 먼저 출발하는 노드
- second = n만큼 뒤떨어져서 출발하는 노드

[Logic]
- n 만큼 first를 이동시킨다.
    - first가 nullptr인 경우, 맨 첫번째 노드를 삭제하는 것을 의미하므로, head를 head->next로 바꿔주고 head를 반환한다.
- first->next가 nullptr을 만날 때까지 first와 second를 계속 이동시킨다.
- second->next를 second->next->next로 바꾸고 head를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/
