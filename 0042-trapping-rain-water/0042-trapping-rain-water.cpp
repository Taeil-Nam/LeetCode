class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxLH = height[l];
        int maxRH = height[r];
        int water = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                l++;
                maxLH = max(maxLH, height[l]);
                water += maxLH - height[l];
            }
            else {
                r--;
                maxRH = max(maxRH, height[r]);
                water += maxRH - height[r];
            }
        }
        return water;
    }
};