class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int res = 0;
        while (left < right){
            int leftHeight = heights[left];
            int rightHeight = heights[right];
            int amount = (right - left) * min(leftHeight, rightHeight);
            res = max(res, amount);
            if (leftHeight <= rightHeight)
                left++;
            else
                right--;
        }
        return res;
    }
};
