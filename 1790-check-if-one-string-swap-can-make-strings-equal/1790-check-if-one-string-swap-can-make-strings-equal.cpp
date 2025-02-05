class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char, int> freq;
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]) cnt++;
            if (cnt >= 3) return false;
            freq[s1[i]]++;
        }
        for (int i = 0; i < s2.size(); i++){
            freq[s2[i]]--;
            if (freq[s2[i]] < 0) return false;
        }
        return true;
    }
};