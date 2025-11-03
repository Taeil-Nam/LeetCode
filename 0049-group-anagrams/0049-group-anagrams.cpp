class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> res;

        for (string str : strs){
            vector<int> cnt(26, 0);
            for (int c : str){
                cnt[c - 'a']++;
            }
            string key = "";
            for (int n : cnt){
                key += n;
            }
            groups[key].push_back(str);
        }
        for (auto& it : groups){
            res.push_back(it.second);
        }
        return res;
    }
};