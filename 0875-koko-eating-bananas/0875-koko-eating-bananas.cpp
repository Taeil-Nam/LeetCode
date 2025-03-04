class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1e9;
        int res = r;
        while (l <= r){
            int m = (l + r) / 2;
            long long cnt = 0;
            for (int pile : piles){
                cnt += (pile + m - 1) / m;
            }
            if (cnt <= h){
                res = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return res;
    }
};