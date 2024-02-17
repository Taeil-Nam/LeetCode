class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int moveSize = k % nums.size();

        reverse(nums.begin(), nums.begin() + (nums.size() - moveSize)); // O(n)
        reverse(nums.begin() + (nums.size() - moveSize), nums.end()); // O(n)
        reverse(nums.begin(), nums.end()); // O(n)
    }
};

// Time complexity = O(n)
// Space complexity = O(1)
