class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int n : nums){
            if (us.count(n) > 0)
                return true;
            us.insert(n);
        }
        return false;
    }
};