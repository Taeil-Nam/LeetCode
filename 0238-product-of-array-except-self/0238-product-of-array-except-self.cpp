class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        nums = [1,2,3,4]
        output = [24,12,8,6]

        prefix = [1, 1, 2,6]
        suffix = [24,12,4,1]
        */
        int N = nums.size();
        int prefix[100000];
        int suffix[100000];

        prefix[0] = 1;
        suffix[N - 1] = 1;
        for (int i = 1; i < N; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }
        for (int i = N - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        vector<int> ans;
        for (int i = 0; i < N; i++) {
            ans.push_back(prefix[i] * suffix[i]);
        }
        
        return ans;
    }
};