class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> seen;

        for (auto num : nums){
            if (seen[num])
                return true;
            seen[num] = true;
        }
        return false;
    }
};