class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int S = nums.size();

        for (int i = 0; i < S; i++) {
            for (int j = i + 1; j < S; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};