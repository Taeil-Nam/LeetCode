class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        int res = 0;
        for (int i = 0; i < N; i++){
            int height = heights[i];
            int left = i;
            int right = i;
            while (left > 0 && height <= heights[left - 1])
                left--;
            while (right < N - 1 && height <= heights[right + 1])
                right++;
            res = max(res, (right - left + 1) * height);
        }
        return res;
    }
};
