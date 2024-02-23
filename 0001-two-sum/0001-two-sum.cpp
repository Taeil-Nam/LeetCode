class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> seen;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            if (seen.find(target - nums[i]) != seen.end())
            {
                result.push_back(seen[target - nums[i]]);
                result.push_back(i);
                break;
            }
            seen[nums[i]] = i;
        }
        return result;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)