class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        go("", 0, 0, n, res);
        return res;
    }
    void go(string s, int openCnt, int closeCnt, int n, vector<string>& res){
        if (openCnt + closeCnt == 2 * n){
            res.push_back(s);
            return;
        }
        if (openCnt < n){
            go(s + "(", openCnt + 1, closeCnt, n, res);
        }
        if (closeCnt < openCnt){
            go(s + ")", openCnt, closeCnt + 1, n, res);
        }
    }
};