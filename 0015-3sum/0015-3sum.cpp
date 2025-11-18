class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                int val = nums[i] + nums[l] + nums[r];
                if (val == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
                else if (val < 0) l++;
                else if (val > 0) r--;
            }
        }
        return res;
    }
};