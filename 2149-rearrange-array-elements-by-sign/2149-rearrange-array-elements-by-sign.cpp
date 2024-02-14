class Solution
{
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> result(nums.size(), 0);
        int positiveIndex = 0;
        int negativeIndex = 1;

        for (int num : nums) // O(n)
        {
            if (num > 0)
            {
                result[positiveIndex] = num;
                positiveIndex += 2;
            }
            else
            {
                result[negativeIndex] = num;
                negativeIndex += 2;
            }
        }
        return result;
    }
};
// Time complexity = O(n)
// Space complexity = O(n)