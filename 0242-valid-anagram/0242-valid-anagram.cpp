class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> freq;

        for (auto c : s){
            freq[c]++;
        }
        for (auto c : t){
            freq[c]--;
        }
        for (auto& it : freq){
            if (it.second != 0)
                return false;
        }
        return true;
    }
};