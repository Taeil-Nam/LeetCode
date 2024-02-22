class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> trusting(n + 1);
        vector<int> trusted(n + 1);
        for (auto value : trust)
        {
            trusting[value[0]]++;
            trusted[value[1]]++;
        }
        int judge = -1;
        for (int i = 1; i <= n; i++)
        {
            if (trusting[i] == 0 && trusted[i] == n - 1)
            {
                judge = i;
                break;
            }
        }
        return judge;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)