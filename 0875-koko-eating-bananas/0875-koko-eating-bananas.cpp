class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1e+9;
        int res = INT_MAX;
        while (l <= r){
            int m = (l + r) / 2;
            long long time = 0;
            for (auto pile : piles){
                time += (pile + m - 1) / m;
            }
            if (time > h)
                l = m + 1;
            else{
                r = m - 1;
                res = min(res, m);
            }
        }
        return res;
    }
};

/*
1 2 3  4 5 6
3 4 5  6 7 8
1 1 1  2 2 2
*/