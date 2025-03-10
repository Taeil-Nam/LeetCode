class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix(N);
        vector<int> suffix(N);
        vector<int> res(N);
        prefix[0] = 1;
        suffix[N - 1] = 1;
        for (int i = 1; i < N; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for (int i = N - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < N; i++){
            res[i] = prefix[i] * suffix[i];
        }
        return res;
    }
};

/*
Input:  [1,2,3,4]
Output: [24,12,8,6]

prefix: [1, 1, 2,6]
suffix: [24,12,4,1]
product:[24,12,8,6]
*/