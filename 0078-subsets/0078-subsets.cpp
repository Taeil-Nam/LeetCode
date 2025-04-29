class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;

        go(nums, subset, res, 0);
        return res;
    }

    void go(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int idx){
        if (idx == nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        go(nums, subset, res, idx + 1);

        subset.pop_back();
        go(nums, subset, res, idx + 1);
    }
};