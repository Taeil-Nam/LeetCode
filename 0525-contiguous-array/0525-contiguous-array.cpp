class Solution
{
public:
    int findMaxLength(vector<int>& nums)
    {
        int sum = 0;
        int maxLength = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 1 ? 1 : -1;
            if (seen.count(sum)) maxLength = ::max(maxLength, i - seen[sum]);
            else seen[sum] = i;
        }
        return maxLength;
    }
};

/*
Approch

[Variables]
- int sum : 요소들의 누적 합을 저장.
- int maxLength : subArray의 최대 길이를 저장.
- unordered_map<int, int> : sum 값이 계산되었을 때의 인덱스(i)를 저장.

[Logic]
- seen[0]을 -1로 초기화 한다. (sum이 0이 나온 경우, 해당 인덱스 + 1을 해주기 위함)
- i를 1씩 올리면서 아래 내용을 반복한다.
    - 현재 요소가 1이면 1, 0이면 -1을 sum에 더한다.
    - seen에 현재 sum에 대한 값이 있는지 확인한다.
        - 있는 경우, 현재 인덱스에서 seen[sum]을 뺀 값이 maxLength보다 높은 경우 maxLength를 갱신한다.
        - 없는 경우, 현재 인덱스를 seen[sum]에 저장한다.
- maxLength를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
