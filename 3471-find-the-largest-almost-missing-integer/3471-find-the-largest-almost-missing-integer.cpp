class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> v(51);
        for (int i = 0; i <= nums.size() - k; i++){
            unordered_set<int> s;
            for (int j = i; j < i + k; j++){
                s.insert(nums[j]);
            }
            for (int n : s){
                v[n]++;
            }
        }
        int res = -1;
        for (int i = 0; i < v.size(); i++){
            if (v[i] == 1)
                res = i;
        }
        return res;
    }
};