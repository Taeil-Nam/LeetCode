class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());
        go(candidates, target, res, comb, 0);
        return res;
    }

    void go(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& comb, int idx){
        if (target < 0){
            return;
        }
        if (target == 0){
            res.push_back(comb);
            return;
        }

        for (int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i - 1] == candidates[i])
                continue;
            if (target - candidates[i] < 0)
                return;
            comb.push_back(candidates[i]);
            go(candidates, target - candidates[i], res, comb, i + 1);
            comb.pop_back();
        }
    }
};