class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for (char c : s)
            um[c]++;
        for (char c : t){
            um[c]--;
        }
        for (auto it : um){
            if (it.second != 0)
                return false;
        }
        return true;
    }
};