class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int l = 0;
        int r = N - 1;
        int maxHL = height[l];
        int maxHR = height[r];
        int water = 0;

        while (l < r) {
            if (maxHL < maxHR) {
                l++;
                maxHL = max(maxHL, height[l]);
                water += maxHL - height[l];
            } else {
                r--;
                maxHR = max(maxHR, height[r]);
                water += maxHR - height[r];
            }
        }
        return water;
    }
};