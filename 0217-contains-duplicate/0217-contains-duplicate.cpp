class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int n : nums){
            if (um[n] > 0) return true;
            um[n]++;
        }
        return false;
    }
};