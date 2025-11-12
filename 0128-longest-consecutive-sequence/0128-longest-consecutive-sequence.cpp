class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int res = 0;

        for (int num : seen){
            if (seen.count(num - 1)) continue;

            int curr = num;
            int len = 0;
            while (seen.count(curr)){
                curr++;
                len++;
            }
            res = max(res, len);
        }
        return res;
    }
};