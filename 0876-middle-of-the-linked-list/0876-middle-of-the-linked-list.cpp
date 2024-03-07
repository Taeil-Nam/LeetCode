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
    ListNode* middleNode(ListNode* head)
    {
        int listSize = 0;
        ListNode* target = head;
        while (head != nullptr) // O(n)
        {
            head = head->next;
            listSize++;
        }
        for (int i = 0; i < listSize / 2; i++) // O(n)
        {
            target = target->next;
        }
        return target;
    }
};

/*
Approch
[Variables]
- int listSize : list의 크기를 저장하는 변수.
- ListNode* target : 타겟 노드를 저장할 포인터.

[Logic]
- head가 nullptr이 아닌경우, head를 next로 바꾸고 listSize를 1 올리는 과정을 반복한다.
- listSize / 2 번 만큼 target을 next로 옮긴다.
- target을 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/
