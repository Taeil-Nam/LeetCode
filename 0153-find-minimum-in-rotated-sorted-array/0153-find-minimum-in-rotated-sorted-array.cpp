class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = INT_MAX;
        while (l <= r){
            res = min(res, nums[l]);
            int m = (l + r) / 2;
            if (nums[l] <= nums[m]){
                l = m + 1;
            }
            else
                r = m - 1;
            res = min(res, nums[m]);
        }
        return res;
    }
};
