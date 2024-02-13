class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int count = 1;

        for (int i = 1; i < nums.size(); i++) // O(n)
        {
            if (nums[i - 1] == nums[i])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > 2)
            {
                nums.erase(nums.begin() + i);
                count--;
                i--;
            }
        }
        return nums.size();
    }
};

// Time complexity = O(n)
// Space complexity = O(1)