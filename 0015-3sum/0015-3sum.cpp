class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int fixedNumber = 0;
        int left = 0;
        int right = 0;
        vector<vector<int> > result;

        sort(nums.begin(), nums.end()); // O(logn)
        for (int i = 0; i < nums.size() - 2; i++) // O(n)
        {
            fixedNumber = nums[i];
            left = i + 1;
            right = nums.size() - 1;

            while (left < right) // O(n)
            {
                if (fixedNumber + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (fixedNumber + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    result.push_back(vector<int>{fixedNumber, nums[left], nums[right]});
                    left++;
                }
            }
        }
        sort(result.begin(), result.end()); // O(logn)
        result.erase(unique(result.begin(), result.end()), result.end()); // O(n)
        return result;
    }
};

// Time complexity = O(n^2)
// Space complexity = O(n)