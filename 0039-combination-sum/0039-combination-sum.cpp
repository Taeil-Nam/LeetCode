class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        
        go(candidates, target, cur, 0);
        return res;
    }

    void go(vector<int>& candidates, int target, vector<int>& cur, int idx){
        if (idx == candidates.size() || target < 0){
            return;
        }
        if (target == 0){
            res.push_back(cur);
            return;
        }

        cur.push_back(candidates[idx]);
        go(candidates, target - candidates[idx], cur, idx);

        cur.pop_back();
        go(candidates, target, cur, idx + 1);
    }
};