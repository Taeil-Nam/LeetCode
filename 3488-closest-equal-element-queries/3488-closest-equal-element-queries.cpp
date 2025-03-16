class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int N = nums.size();
        unordered_map<int, pair<int, int>> um;
        vector<int> dists(N, -1);
        for (int i = 0; i < nums.size(); i++){
            if (um.count(nums[i]) == 0){
                um[nums[i]].first = i;
                um[nums[i]].second = i;
                continue;
            }
            else{
                int minPrev = um[nums[i]].first;
                int maxPrev = um[nums[i]].second;
                um[nums[i]].first = min(um[nums[i]].first, i);
                um[nums[i]].second = max(um[nums[i]].second, i);
                int dist1 = i - maxPrev;
                int dist2 = N - (i + 1) + minPrev + 1;
                if (minPrev == maxPrev){
                    dists[minPrev] = min(dist1, dist2);
                }
                else{
                    dists[maxPrev] = min(dists[maxPrev], dist1);
                    dists[minPrev] = min(dists[minPrev], dist2);
                }
                dists[i] = min(dist1, dist2);
            }
        }
        vector<int> res;
        for (int i : queries){
            res.push_back(dists[i]);
        }
        return res;
    }
};
