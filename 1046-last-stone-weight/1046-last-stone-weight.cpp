class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() >= 2){
            int r = pq.top(); pq.pop();
            int l = pq.top(); pq.pop();
            
            if (l == r) continue;
            else pq.push(r - l);
        }
        if (pq.empty()) return 0;
        return pq.top();
    }
};