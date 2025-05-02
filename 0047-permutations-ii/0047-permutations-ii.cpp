class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;

        permutation(nums, res, s, 0);
        for (auto it : s)
            res.push_back(it);
        return res;
    }

    void permutation(vector<int>& nums, vector<vector<int>>& res, set<vector<int>>& s, int start){
        if (start == nums.size()){
            s.insert(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            permutation(nums, res, s, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};