class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int num : nums){
            um[num]++;
            if (um[num] > 1)
                return num;
        }
        return 0;
    }
};