class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int fixedNumber = 0;
        int left = 0;
        int right = 0;
        vector<vector<int> > result;
        set<vector<int> > set;  // for remove duplicate triplets

        sort(nums.begin(), nums.end()); // O(nlogn)
        for (int i = 0; i < nums.size() - 2; i++) // O(n)
        {
            fixedNumber = nums[i];
            left = i + 1;
            right = nums.size() - 1;

            while (left < right) // O(n)
            {
                if (fixedNumber + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if (fixedNumber + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    set.insert(vector<int>{fixedNumber, nums[left], nums[right]}); // O(logn)
                    left++;
                }
            }
        }
        for (auto triplets : set) // O(n)
        {
            result.push_back(triplets);
        }
        return result;
    }
};

// Time complexity = O(n^2 * logn)
// Space complexity = O(n)
