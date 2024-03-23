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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* result = new ListNode();
        ListNode* head = result;
        while (list1 != nullptr && list2 != nullptr) // O(n)
        {
            if (list1->val <= list2->val)
            {
                result->next = list1;
                result = result->next;
                list1 = list1->next;
            }
            else
            {
                result->next = list2;
                result = result->next;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr) // O(n)
        {
            result->next = list1;
            result = result->next;
            list1 = list1->next;
        }
        while (list2 != nullptr) // O(n)
        {
            result->next = list2;
            result = result->next;
            list2 = list2->next;
        }
        return head->next;
    }
};

/*
[Approch]
- 새로운 list의 dummy head를 만든다.
- list1, list2를 처음부터 하나씩 비교하면서 아래 내용을 수행한다:
    - 작은 값을 가진 노드 = 새로운 list->next로 설정한다.
- list1을 전부 순회하면서 새로운 list에 추가한다.
- list2를 전부 순회하면서 새로운 list에 추가한다.
- 만들어진 리스트의 dummy head->next를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
