class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> cnt;
        vector<vector<int>> freq(nums.size() + 1);
        for (int n : nums)
            cnt[n]++;
        for (auto p : cnt)
            freq[p.second].push_back(p.first);
        for (int i = nums.size(); i >= 0; i--){
            for (int num : freq[i]){
                res.push_back(num);
                if (res.size() >= k)
                    return res;
            }
        }
        
        return res;
    }
};
/*
1 : 3
2 : 2
3 : 1
*/