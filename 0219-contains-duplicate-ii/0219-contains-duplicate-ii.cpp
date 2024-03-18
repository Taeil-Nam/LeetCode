class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            if (seen.count(nums[i]) == 0)
                seen[nums[i]] = i;
            else
            {
                if (::abs(seen[nums[i]] - i) <= k)
                    return true;
                else
                    seen[nums[i]] = i;
            }
        }
        return false;
    }
};

/*
Approch

[Variables]
- unordered_map<int, int> seen : <값, 값이 나왔던 인덱스> 를 저장.

[Logic]
- nums의 원소를 순회하면서 아래 내용을 반복한다:
    - 원소가 한번도 안나온경우, seen에 현재 원소의 인덱스를 기록한다.
    - 원소가 나왔던 경우
        - 이전 인덱스(seen[nums[i]]) - 현재 인덱스(i)의 절대 값 <= k 인 경우 true 반환.
        - 절대 값 > k 인 경우, 현재 인덱스로 다시 기록.
- false 반환.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
