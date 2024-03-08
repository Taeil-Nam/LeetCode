class Solution
{
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        vector<int> seen(101, 0);
        for (int n : nums) // O(n)
        {
            seen[n]++;
        }

        int maxFreq = *::max_element(seen.begin(), seen.end()); // O(n)
        int result = 0;
        for (int i = 0; i < seen.size(); i++) // O(n)
        {
            if (seen[i] == maxFreq)
            {
                result += seen[i];
            }
        }
        return result;
    }
};

/*
Approch
[Variables]
- vector<int> seen : 숫자들의 빈도수를 저장하는 hash table.
- int maxFreq : 가장 높은 빈도수를 저장.
- int result : 가장 높은 빈도수를 가지는 숫자들의 빈도수의 합.

[Logic]
- seen을 0의 값을 가진 101개의 요소를 가지도록 초기화한다.
- nums를 전부 순회하면서 seen에 빈도수를 저장한다. (index = 숫자, value = 빈도수)
- ::max_element()를 사용하여 seen에서 가장 큰 값(빈도수)을 maxFreq에 저장한다.
- seen를 전부 순회하면서 maxFreq와 동일한 값을 가진 경우, result에 더해준다.
- result를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
- 문제의 제한 사항은 1 <= nums.length <= 100, 1 <= nums[i] <= 100 으로 정해져 있지만,
    상수가 아닌 n으로 판단함.
*/
