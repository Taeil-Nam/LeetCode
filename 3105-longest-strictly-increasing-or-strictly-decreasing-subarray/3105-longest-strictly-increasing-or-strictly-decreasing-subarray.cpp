class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increaseCnt = 1;
        int decreaseCnt = 1;
        int maxIncreaseCnt = 1;
        int maxDecreaseCnt = 1;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] - nums[i + 1] < 0){
                increaseCnt++;
                maxIncreaseCnt = max(maxIncreaseCnt, increaseCnt);
                decreaseCnt = 1;
            }
            else if (nums[i] - nums[i + 1] > 0){
                decreaseCnt++;
                maxDecreaseCnt = max(maxDecreaseCnt, decreaseCnt);
                increaseCnt = 1;
            }
            else{
                increaseCnt = 1;
                decreaseCnt = 1;
            }
        }
        return max(maxIncreaseCnt, maxDecreaseCnt);
    }
};
// 3 2 3 4 5