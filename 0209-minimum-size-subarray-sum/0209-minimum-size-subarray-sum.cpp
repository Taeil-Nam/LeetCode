class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left = 0;
        int right = 0;
        int minLength = numeric_limits<int>::max();
        int sum = 0;
        while (right < nums.size()) // O(n)
        {
            sum += nums[right];
            right++;
            while (sum >= target) // O(n)
            {
                minLength = ::min(minLength, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return minLength == numeric_limits<int>::max() ? 0 : minLength;
    }
};

// Time complexity = O(n + n) = O(n)
// Space complexity = O(1)

/*

Approch
- sliding window 기법을 사용하여 subarray를 판별.

- sliding window의 범위를 나타내는 left, right 변수 사용.
- 가장 작은 subarray size를 저장할 minLength 변수 사용.
- sliding window 범위의 요소들의 합을 저장할 sum 변수 사용.

1. sum에 right가 가리키고 있는 nums의 요소를 더한다.
2. right를 한칸 옆으로 이동한다.
3. 현재까지 범위의 합이 target보다 크거나 같은 경우, 해당 범위 안에서 해당 조건을 만족하는 가장 작은 범위를 찾는다.
    3-1. 현재 범위와 minLength의 범위를 비교하여, 작은 것을 minLength로 갱신한다.
    3-2. sum에서 left가 가리키고 있는 요소를 빼준 후, left를 오른쪽으로 한칸 옮긴다.
    3-3. sum이 target보다 크거나 같을 때까지 반복한다.
    3-4. sum이 target보다 작다면, 범위를 늘려야 하므로 1번 과정부터 다시 시작한다.
4. minLength가 처음에 초기화했던 INT_MAX와 같다면 0을 return, 아닌 경우 해당 minLength 값을 return 한다.

위의 접근법을 사용하면, 조건을 만족하는 window 범위를 찾은 후, 최대한 범위를 줄이면서 해답을 찾게 된다.

*/
