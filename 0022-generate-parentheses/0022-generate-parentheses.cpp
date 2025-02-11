class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        go("", n, res);
        return res;
    }
    void go(string s, int n, vector<string>& res){
        if (s.size() == n * 2){
            int openCnt = 0;
            for (char c : s){
                if (c == '(')
                    openCnt++;
                else
                    openCnt--;
                if (openCnt < 0) return;
            }
            if (openCnt == 0) res.push_back(s);
            return;
        }
        go(s + "(", n, res);
        go(s + ")", n, res);
    }
};