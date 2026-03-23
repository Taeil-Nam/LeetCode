class NumArray {
public:
    NumArray(vector<int>& nums) {
        N = nums.size();
        psum = vector<int>(N, 0);

        for (int i = 0; i < N; i++){
            if (i == 0){
                psum[i] = nums[i];
                continue;
            }
            psum[i] = psum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return psum[right];
        }
        else {
            return psum[right] - psum[left - 1];
        }
    }

private:
    int N;
    vector<int> psum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */