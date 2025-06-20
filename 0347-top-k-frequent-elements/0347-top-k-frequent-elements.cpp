class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for (int n : nums){
            freq[n]++;
        }
        for (auto& pair : freq){
            pq.push({pair.second, pair.first});
        }
        while (k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};