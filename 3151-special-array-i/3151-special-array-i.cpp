class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool even = false;
        if ((nums[0] % 2) == 0)
            even = true;
        for (int i = 1; i < nums.size(); i++){
            if (even && (nums[i] % 2) == 0)
                return false;
            else if (!even && (nums[i] % 2) == 1)
                return false;
            even = (nums[i] % 2) == 0;
        }
        return true;
    }
};
