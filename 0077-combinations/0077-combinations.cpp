void combi_recur(int start, vector<int>& b, vector<vector<int>>& res, int n, int k){
    if (b.size() == k){
        res.push_back(b);
        return;
    }
    for (int i = start + 1; i <= n; i++){
        b.push_back(i);
        combi_recur(i, b, res, n, k);
        b.pop_back();
    }
    return;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> b;
        vector<vector<int>> res;
        combi_recur(0, b, res, n, k);
        return res;
    }
};