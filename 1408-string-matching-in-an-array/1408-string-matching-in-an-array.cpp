class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (string word : words){
            for (string target : words){
                if (word == target)
                    continue;
                if (target.find(word) != string::npos){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};