class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> combi;

        backTrack(s, res, combi, 0);
        return res;
    }

    void backTrack(string& s, vector<vector<string>>& res, vector<string>& combi, int start){
        if (start == s.size()){
            res.push_back(combi);
            return;
        }

        for (int i = start; i < s.size(); i++){
            if (isPalindrome(s, start, i)){
                combi.push_back(s.substr(start, i - start + 1));
                backTrack(s, res, combi, i + 1);
                combi.pop_back();
            }
        }
    }

    bool isPalindrome(string& str, int i, int j){
        while (i < j){
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};