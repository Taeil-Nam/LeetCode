class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int, vector<int>, greater<int>> res;
        int N = grid.size();
        int M = grid[0].size();
        for (int row = 0; row < N; row++){
            int cnt = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            for (int col = 0; col < M; col++){
                int val = grid[row][col];
                if (cnt >= limits[row]){
                    if (pq.size() && val > pq.top()){
                        pq.pop();
                        pq.push(val);
                    }
                }
                else{
                    pq.push(val);
                    cnt++;
                }
            }
            while (pq.size()){
                res.push(pq.top());
                pq.pop();
            }
        }
        long long sum = 0;
        while (res.size() > k) res.pop();
        while (res.size()){
            sum += res.top();
            res.pop();
        }
        return sum;
    }
};

/*
[16,18,7, 27,43,45,50,4, 29] 8 6
[31,8, 42,26,47,47,23,22,40] 2

*/