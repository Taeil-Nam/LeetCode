class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for (char c : s1){
            freq[c]++;
        }
        for (int l = 0; l + s1.size() <= s2.size(); l++){
            unordered_map<char, int> temp = freq;
            int cnt = 0;
            for (int i = 0; i < s1.size(); i++){
                if (temp[s2[l + i]] == 0){
                    break;
                }
                else{
                    temp[s2[l + i]]--;
                    cnt++;
                }
            }
            if (cnt == s1.size())
                return true;
        }
        return false;
    }
};
