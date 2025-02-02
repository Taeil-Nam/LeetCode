class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        vector<vector<int>> freq(nums.size() + 1);
        for (int n : nums)
            cnt[n]++;
        for (auto& pair : cnt){
            freq[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; i--){
            for (auto n : freq[i]){
                res.push_back(n);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
