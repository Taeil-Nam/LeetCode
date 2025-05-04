class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        int res = 1;

        while (n > 0){
            pq.push(n % 10);
            n /= 10;
        }
        for (int i = 0; i < 2; i++){
            res *= pq.top();
            pq.pop();
        }
        return res;
    }
};