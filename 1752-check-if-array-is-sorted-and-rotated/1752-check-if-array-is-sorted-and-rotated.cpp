class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); i++){
            if (sorted == nums)
                return true;
            rotate(sorted.begin(), sorted.begin() + 1, sorted.end());
        }
        return false;
    }
};