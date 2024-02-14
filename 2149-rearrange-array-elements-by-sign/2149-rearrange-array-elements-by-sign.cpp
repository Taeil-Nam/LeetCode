class Solution
{
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        unordered_map<int, bool> indexHash;
        vector<int> result;
        bool wasPositive = false;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > 0 && wasPositive == false && indexHash[i] == false)
        //     {
        //         result.push_back(nums[i]);
        //         wasPositive = true;
        //         indexHash[i] = true;
        //         i = -1;
        //     }
        //     else if (nums[i] < 0 && wasPositive == true && indexHash[i] == false)
        //     {
        //         result.push_back(nums[i]);
        //         wasPositive = false;
        //         indexHash[i] = true;
        //         i = -1;
        //     }
        // }
        // O(n^2) -> Time limits exceeded

        int positiveIndex = 0;
        int negativeIndex = 0;
        while (positiveIndex < nums.size() && negativeIndex < nums.size())
        {
            while (nums[positiveIndex] < 0 && positiveIndex < nums.size()) // O(n)
            {
                positiveIndex++;
            }
            while (nums[negativeIndex] > 0 && negativeIndex < nums.size()) // O(n)
            {
                negativeIndex++;
            }
            if (positiveIndex < nums.size() && wasPositive == false)
            {
                result.push_back(nums[positiveIndex]);
                positiveIndex++;
                wasPositive = true;
            }
            if (negativeIndex < nums.size() && wasPositive == true)
            {
                result.push_back(nums[negativeIndex]);
                negativeIndex++;
                wasPositive = false;
            }
        }
        return result;
    }
};
// Time complexity = O(n)
// Space complexity = O(n)