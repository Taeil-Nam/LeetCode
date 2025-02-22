class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int curPrice : prices){
            maxProfit = max(maxProfit, curPrice - minPrice);
            minPrice = min(minPrice, curPrice);
        }
        return maxProfit;
    }
};