class Solution
{
public:
    long long largestPerimeter(vector<int>& nums)
    {
        long long sum = 0;

        sort(nums.begin(), nums.end(), greater<int>());
        for (int num : nums) // O(n)
        {
            sum += num;
        }
        for (int num : nums) // O(n)
        {
            sum -= num;
            if (sum > num)
            {
                return sum + num;
            }
        }
        return -1;
    }
};

// Time complexity = O(n)
// Space complexity = O(1)
// [50,12,4,3,2,1,1]