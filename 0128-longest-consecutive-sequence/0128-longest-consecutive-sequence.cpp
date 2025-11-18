class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : seen) {
            if (seen.count(num - 1)) continue;
            
            int len = 1;
            while (seen.count(num + 1)) {
                len++;
                num++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};