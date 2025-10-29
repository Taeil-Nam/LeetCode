class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> freq_s;
        unordered_map<int, int> freq_t;

        if (s.size() != t.size())
            return false;
        for (auto c : s){
            freq_s[c]++;
        }
        for (auto c : t){
            freq_t[c]++;
        }
        for (auto& it : freq_t){
            if (freq_s[it.first] != it.second)
                return false;
        }
        return true;
    }
};