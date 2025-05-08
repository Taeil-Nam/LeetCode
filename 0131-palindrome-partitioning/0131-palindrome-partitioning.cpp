class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;

        backTrack(s, res, part, 0);
        return res;
    }

    void backTrack(string& s, vector<vector<string>>& res, vector<string>& part, int start){
        if (start == s.size()){
            res.push_back(part);
            return;
        }

        for (int i = start; i < s.size(); i++){
            if (isPalindrome(s, start, i)){
                part.push_back(s.substr(start, i - start + 1));
                backTrack(s, res, part, i + 1);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int start, int i){
        while (start < i){
            if (s[start] != s[i])
                return false;
            start++;
            i--;
        }
        return true;
    }
};