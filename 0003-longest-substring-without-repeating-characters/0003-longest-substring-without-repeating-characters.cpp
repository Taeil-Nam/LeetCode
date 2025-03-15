class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int res = 0;
        int l = 0;
        int r = 0;
        while (r < s.size()){
            if (charMap.count(s[r])){
                l = max(l, charMap[s[r]] + 1);
            }
            charMap[s[r]] = r;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};