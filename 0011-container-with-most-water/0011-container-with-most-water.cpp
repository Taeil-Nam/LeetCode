class Solution
{
public:
    int maxArea(vector<int>& height) 
    {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        int x = 0;
        int y = 0;

        while (left <= right)
        {
            x = right - left;
            y = height[left] <= height[right] ? height[left] : height[right];
            if (x * y > result)
            {
                result = x * y;
            }
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};

