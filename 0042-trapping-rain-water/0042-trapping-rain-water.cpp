class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftWall = height[left];
        int rightWall = height[right];
        int res = 0;
        while (left < right){
            if (leftWall < rightWall){
                left++;
                leftWall = max(leftWall, height[left]);
                res += leftWall - height[left];
            }
            else{
                right--;
                rightWall = max(rightWall, height[right]);
                res += rightWall - height[right];
            }
        }
        return res;
    }
};