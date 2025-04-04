class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i - 1]  < nums[i]){
                sum += nums[i];
                res = max(res, sum);
            }
            else{
                sum = nums[i];
            }
        }
        return res;
    }
};