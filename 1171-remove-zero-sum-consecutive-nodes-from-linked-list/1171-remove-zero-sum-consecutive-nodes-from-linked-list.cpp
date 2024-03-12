/**
 * Definition for singly-linked list.
 * struct ListNode
 {
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
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        vector<int> arr;
        while (head != nullptr) // O(n)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        int start = 0;
        while (start < arr.size()) // O(n)
        {
            int sum = 0;
            int end = start;
            int sign = false;
            while (end < arr.size()) // O(n)
            {
                sum += arr[end];
                if (sum == 0)
                {
                    arr.erase(arr.begin() + start, arr.begin() + end + 1); // O(n)
                    sign = true;
                    break;
                }
                else
                {
                    end++;
                }
            }
            if (sign == true) continue;
            start++;
        }
        if (arr.size() == 0) return nullptr;
        ListNode* result = new ListNode(arr[0]);
        head = result;
        for (int i = 1; i < arr.size(); i++) // O(n)
        {
            result->next = new ListNode(arr[i]);
            result = result->next;
        }
        return head;
    }
};

/*
Approch
[Variables]
- vector<int> arr : 연결리스트를 배열로 변환한 배열.
- int sum : 노드들의 합을 저장.
- int start : 첫 노드를 저장.
- int end : 마지막 노드를 저장.
- int sign : 배열의 삭제 유무를 저장.
- ListNode* result : 결과 리스트를 저장.

[Logic]
- 연결리스트를 배열로 변환한다.
- 배열에서 합이 0이 되는 경우를 찾고 지운다.
- 수정된 배열을 참고하여 연결리스트로 변환한다.

[Complexity]
- Time complexity = O(n^3)
- Space complexity = O(n)
*/
