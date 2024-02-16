class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        int count = 0;
        unordered_map<int, int> frequency;
        vector<int> sorted;
        for (int num : arr) // O(n)
        {
            frequency[num]++;
        }
        for (auto pair : frequency) // O(n)
        {
            sorted.push_back(pair.second);
        }
        sort(sorted.begin(), sorted.end()); // O(nlogn)
        for (int i = 0; i < sorted.size(); i++) // O(n)
        {
            if (sorted[i] < k)
            {
                k -= sorted[i];
                sorted[i] = 0;
            }
            else
            {
                sorted[i] -= k;
                k = 0;
            }
            if (sorted[i] != 0)
            {
                count++;
            }
        }
        return count;
    }
};

// Time complexity = O(nlogn)
// Space complexity = O(n)