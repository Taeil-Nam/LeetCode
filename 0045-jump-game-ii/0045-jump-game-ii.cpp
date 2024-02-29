class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int start = 0;
        int end = 0;
        int maxIndex = 0;
        int jumpCount = 0;
        while (maxIndex < nums.size() - 1) // O(n)
        {
            jumpCount++;
            for (int i = start; i <= end; i++)
            {
                maxIndex = ::max(maxIndex, nums[i] + i);
            }
            start = end + 1;
            end = maxIndex;
        }
        return jumpCount;
    }
};

// Time complexity = O(n)
// Space complexity = O(1)

/*
Approch
[variables]
- start = 현재 index에서 갈 수 있는 index 범위 중 첫 번째 index.
- end = 현재 index에서 갈 수 있는 index 범위 중 마지막 index.
- maxIndex = 현재 index에서 갈 수 있는 가장 멀리 있는 index.
- jumpCount = jump 횟수.

[logic]
- maxIndex가 주어진 배열의 마지막 index보다 작은 경우 아래 내용을 반복.
    - jumpCount에 1을 더한다.
    - start에서 end 범위에서 각 index들의 값과, 현재 maxIndex의 값 중 더 큰 값을 maxIndex에 대입한다.
        - 이때, 현재 index + 현재 index의 값 = 갈 수 있는 최대 거리이므로, nums[i] + i 로 계산한다.
    - start를 end + 1 의 index로 옮긴다.
    - end를 maxIndex로 옮긴다.
- 반복문이 끝났다는 것은, 마지막 index로 갈 수 있는 최단 거리를 찾은 것이다.
- jumpCount를 반환한다.
*/