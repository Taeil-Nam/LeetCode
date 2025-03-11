class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        go(res, n, "(", 1, 0);
        return res;
    }

    void go(vector<string>& res, int n, string s, int openCnt, int closeCnt){
        if (openCnt > n || closeCnt > n || closeCnt > openCnt)
            return;
        if (s.size() == n * 2){
            res.push_back(s);
            return;
        }
        go(res, n, s + "(", openCnt + 1, closeCnt);
        go(res, n, s + ")", openCnt, closeCnt + 1);
    }
};