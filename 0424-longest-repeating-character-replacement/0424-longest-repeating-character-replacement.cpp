class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxFreq = 0;
        int res = 0;
        unordered_map<char, int> freq;
        while (right < s.size()){
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);
            while ((right - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};