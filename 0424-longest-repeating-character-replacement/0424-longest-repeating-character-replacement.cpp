class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int l = 0;
        int r = 0;
        int res = 0;
        while (r < s.size()){
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while ((r - l + 1) - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};