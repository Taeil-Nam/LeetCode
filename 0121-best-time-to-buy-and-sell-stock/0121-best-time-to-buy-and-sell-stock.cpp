class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int result = 0;
        int minNumber = numeric_limits<int>::max();
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minNumber)
            {
                minNumber = prices[i];
            }
            profit = prices[i] - minNumber;
            if (profit > result)
            {
                result = profit;
            }
        }
        return result;
    }
};

// O(n^2) : time limit exceeded
// 8 5 9 2 7