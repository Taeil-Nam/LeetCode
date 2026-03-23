class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            if (i == 0){
                psum.push_back(nums[i]);
                continue;
            }
            psum.push_back(psum[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return psum[right];
        else
            return psum[right] - psum[left - 1];
    }

private:
    vector<int> psum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */