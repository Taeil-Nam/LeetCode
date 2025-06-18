class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++){
            if (freq.count(target - nums[i]))
                return {i, freq[target - nums[i]]};
            freq[nums[i]] = i;
        }
        return {};
    }
};