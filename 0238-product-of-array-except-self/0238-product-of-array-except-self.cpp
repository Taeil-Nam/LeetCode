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
1  1  2  8 prefix
1  2  4  6 nums
48 24 6  1 suffix
48 24 12 8 res
*/