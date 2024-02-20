class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int target = 0;
        sort(nums.begin(), nums.end()); // O(nlogn)
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            if (nums[i] != target)
            {
                break;
            }
            target++;
        }
        return target;
    }
};

// Time complexity = O(nlogn)
// Space complexity = O(1)