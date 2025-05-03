class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        set<vector<int>> s;

        sort(nums.begin(), nums.end());
        go(nums, res, comb, s, 0);
        for (auto it : s){
            res.push_back(it);
        }
        return res;
    }

    void go(vector<int>& nums, vector<vector<int>>& res, vector<int>& comb, set<vector<int>>& s, int idx){
        if (idx == nums.size()){
            s.insert(comb);
            return;
        }

        comb.push_back(nums[idx]);
        go(nums, res, comb, s, idx + 1);

        comb.pop_back();
        go(nums, res, comb, s, idx + 1);
    }
};