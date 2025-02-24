class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < s.size()){
            if (charMap.find(s[right]) != charMap.end()){
                left = max(left, charMap[s[right]] + 1);
            }
            charMap[s[right]] = right;
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};