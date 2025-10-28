class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++){
            seen[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            if (seen[target - nums[i]] && i != seen[target - nums[i]])
                return {i, seen[target - nums[i]]};
        }
        return {};
    }
};