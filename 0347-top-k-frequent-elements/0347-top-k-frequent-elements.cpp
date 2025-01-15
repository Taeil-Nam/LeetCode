class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> um;
        vector<vector<int>> freq(nums.size() + 1);
        for (auto n : nums)
            um[n]++;
        for (auto [a, b] : um)
            freq[b].push_back(a);
        for (int i = nums.size(); i > 0; i--){
            for (auto n : freq[i]){
                if (res.size() == k)
                    return res;
                res.push_back(n);
            }
        }
        return res;
    }
};
/*
[1] : 3
[2] : 2
[3] : 1
*/