class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, int> hashMap;
        for (auto num : nums) // O(n)
        {
            hashMap[num]++;
        }
        for (auto value : hashMap) // O(n)
        {
            if (value.second >= 2)
            {
                return true;
            }
        }
        return false;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)