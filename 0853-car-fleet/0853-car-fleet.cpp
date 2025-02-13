class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int N = position.size();
        vector<pair<int, double>> v;
        for (int i = 0; i < N; i++){
            v.push_back({position[i], (double)(target - position[i]) / speed[i]});
        }
        sort(v.rbegin(), v.rend());
        double prevTime = 0;
        int res = 0;
        for (auto& [pos, time] : v){
            if (prevTime < time){
                prevTime = time;
                res++;
            }
        }
        return res;
    }
};
