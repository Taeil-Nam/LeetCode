class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int cnt = 0;
        int sum = 0;
        while (cnt < n * n){
            sum += w;
            if (sum > maxWeight)
                break;
            cnt++;
        }
        return cnt;
    }
};