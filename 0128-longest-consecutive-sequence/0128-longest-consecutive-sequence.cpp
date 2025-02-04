class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet;
        for (int num : nums){
            numsSet.insert(num);
        }
        int beforeNum = INT_MIN;
        int cnt = 1;
        int res = 0;
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