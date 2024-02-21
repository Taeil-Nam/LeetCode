class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int jumpCount = nums[0];
        for (int i = 1; i < nums.size(); i++) // O(n)
        {
            jumpCount--;
            if (jumpCount < 0)
            {
                return false;
            }
            if (jumpCount < nums[i])
            {
                jumpCount = nums[i];
            }
        }
        return true;
    }
};

// Time complexity = O(n)
// Space complexity = O(1)