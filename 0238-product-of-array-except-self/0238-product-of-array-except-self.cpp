class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> answer(nums.size(), 1);
        int curr = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            answer[i] *= curr; // 1 1 2 6
            curr *= nums[i]; // 1 2 6 24
        }
        curr = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            answer[i] *= curr; // 24 12 8 6
            curr *= nums[i]; // 4 12 24 24
        }
        return answer;
    }
};

/*
[Variables]
- vector<int> answer : i 번째 요소들 제외한 나머지 요소들의 곱셈 결과를 저장.
- int curr : 현재까지의 누적곱 저장.

[Logic]
- answer의 요소들을 1로 초기화한다.
- curr를 1로 초기화한다.
- i를 제외한 왼쪽 부분의 곱을 구한다. (첫 번째 for loop)
- i를 제외한 오른쪽 부분의 곱을 구하고, 미리 구해뒀던 왼쪽 부분의 곱과 곱한다.(두 번째 for loop)
- answer를 반환한다.

[Comoplexity]
- Time complexity = O(n)
- Space complexity = O(1) : answer는 제외.
*/