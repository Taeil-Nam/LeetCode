class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int N = nums.size();
        int cnt = 0;
        int psum[105];
        psum[0] = 0;
        for (int i = 1; i <= N; i++){
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i < N; i++){
            if ((psum[i] - (psum[N] - psum[i])) % 2 == 0) cnt++;
        }
        return cnt;
    }
};

/*
psum = [0, 10, 20, 23, 30, 36]
*/