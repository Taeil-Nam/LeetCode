class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int res = 0;
        int l = 0;
        int r = N - 1;

        while (l < r) {
            int h = min(height[l], height[r]);
            int area = (r - l) * h;

            res = max(res, area);
            
            if (height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
};