class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        * Data structure
        - hashmap<string, vector<int>>

        * Algorithm
        1. Sort string and use this as a key of hashmap.
        2. Add original string to vector in hashmap.
        3. push_back each vector to result vector.
        */
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> res;

        for (string str : strs){
            string key = str;
            sort(key.begin(), key.end());
            hashMap[key].push_back(str);
        }
        for (auto& it : hashMap){
            res.push_back(it.second);
        }
        return res;
    }
};