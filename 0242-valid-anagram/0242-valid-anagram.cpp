class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        if (s.size() != t.size())
            return false;
        for (char c : s)
            um[c]++;
        for (char c : t){
            um[c]--;
            if (um[c] < 0)
                return false;
        }
        return true;
    }
};