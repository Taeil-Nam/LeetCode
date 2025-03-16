class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> freq;
        int mx = INT_MIN;
        bool allNegetive = true;
        for (int n : nums){
            if (n > 0)
                allNegetive = false;
            mx = max(mx, n);
        }
        if (allNegetive)
            return mx;
        int sum = 0;
        for (int n : nums){
            if (freq.count(n) || n <= 0)
                continue;
            freq[n]++;
            sum += n;
        }
        return sum;
    }
};