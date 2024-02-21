class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int count = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            count++;
        }
        return (left << count);
    }
};

// Time Complexity = O(logn). Because right-shift means divide with 2.
// Space Complexity = O(1)
