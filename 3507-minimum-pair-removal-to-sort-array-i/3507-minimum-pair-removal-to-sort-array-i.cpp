class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        while (true){
            int targetIdx = 0;
            int minSum = INT_MAX;
            if (isSorted(nums)) break;

            for (int i = 0; i < nums.size() - 1; i++){
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum){
                    minSum = sum;
                    targetIdx = i;
                }
            }
            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx + 1);
            res++;
        }
        return res;
    }

    bool isSorted(vector<int>& nums){
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
};