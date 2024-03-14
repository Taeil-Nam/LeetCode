class Solution
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        /*
        [문제]
        - 0과 1로 되어있는 벡터의 요소들 중에 합이 goal이 되는 부분 배열이 몇개인지 반환.

        [로직1 - brute force] : 시간초과(O(n^2))
        - nums의 첫 번째 요소부터 마지막 요소를 탐색하면서 아래 내용을 반복한다.
            - sum을 0으로 초기화한다.
            - 현재 요소부터 마지막까지 하나씩 탐색하면서 sum을 구한다.
                - sum = goal인 경우 result를 1 올린다.
        - result를 반환한다.

        [로직2 - hash Map]
        - 
        */

        unordered_map<int, int> count;
        int sum = 0, result = 0;
        count[0] = 1;
        for (int num : nums) // O(n)
        {
            sum += num; // 1, 1, 2, 2, 3
            result += count[sum - goal]; // 0 0 1 2 4
            count[sum]++; // 0:1, 1:2, 2:2, 3:1
        }
        return result;
    }
};
