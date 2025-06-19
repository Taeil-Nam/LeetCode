class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string s : strs){
            vector<int> cnt(26, 0);
            for (char c : s){
                cnt[c - 'a']++;
            }
            string key = "";
            for (int n : cnt){
                key += "," + to_string(n);
            }
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (const auto& pair : groups){
            res.push_back(pair.second);
        }
        return res;
    }
};