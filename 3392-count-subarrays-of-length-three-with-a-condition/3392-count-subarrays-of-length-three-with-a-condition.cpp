class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = 1, k = 2; k < nums.size(); i++, j++, k++){
            if ((nums[i] + nums[k]) * 2 == nums[j])
                res++;
        }
        return res;
    }
};