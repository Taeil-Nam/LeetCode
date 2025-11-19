class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int l = 0;
        int r = N - 1;
        int maxL = height[l];
        int maxR = height[r];
        int res = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                l++;
                if (maxL < height[l])
                    maxL = height[l];
                else
                    res += maxL - height[l];
            }
            else {
                r--;
                if (maxR < height[r])
                    maxR = height[r];
                else
                    res += maxR - height[r];
            }
        }
        return res;
    }
};