class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end()); // O(nlogn)
        return nums;
    }
};

/*
Approch
[Logic]
- nums의 모든 요소들을 각 요소의 제곱수로 만든다.
- nums를 정렬한다.
- nums를 반환한다.
*/
