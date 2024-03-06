/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode*, int> seen;
        while (head != nullptr) // O(n)
        {
            if (seen.count(head) > 0)
            {
                return true;
            }
            seen[head]++;
            head = head->next;
        }
        return false;
    }
};

/*
Approch
[Variables]
- unordered_map<ListNode*, int> seen : 순회한 노드의 주소를 기록해두는 변수

[Logic]
- head가 nullptr이 아닌경우 아래 내용을 반복한다.
    - seen에 현재 head 주소가 기록되어 있다면, 사이클 구조라는 뜻이므로 true를 반환한다.
    - seen에 현재 head를 기록한다.
    - head를 next 노드로 변경한다.
- 순회를 마치면 사이클 구조가 아니므로 false를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
