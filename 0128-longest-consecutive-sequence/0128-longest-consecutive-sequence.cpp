class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> numsSet;
        for (int num : nums){
            numsSet.insert(num);
        }
        int beforeNum = INT_MIN;
        int cnt = 1;
        int res = 1;
        for (int num : numsSet){
            if (num == beforeNum + 1){
                cnt++;
                res = max(res, cnt);
            }
            else{
                cnt = 1;
            }
            beforeNum = num;
        }
        return res;
    }
};