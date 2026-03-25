class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> psum(N + 1, 0);
        unordered_map<int, int> seen;
        int res = 0;

        psum[0] = 0;
        for (int i = 1; i <= N; i++){
            psum[i] = psum[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= N; i++){
            if (psum[i] == k) res++;
            if (seen[psum[i] - k]) res += seen[psum[i] - k];
            seen[psum[i]]++;
        }

        return res;
    }
};