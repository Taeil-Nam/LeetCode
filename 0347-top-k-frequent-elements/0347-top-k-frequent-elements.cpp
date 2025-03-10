class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (auto n : nums){
            um[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto& pair: um){
            pq.push({pair.second, pair.first});
        }
        vector<int> res;
        while (k){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};
