class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int right = 0;
        int max = 0;
        unordered_set<int> seen;
        while (right < s.length())
        {
            auto it = seen.find(s[right]);
            if (it == seen.end())
            {
                if (right - left + 1 > max)
                {
                    max = right - left + 1;
                }
                seen.insert(s[right]);
                right++;
            }
            else
            {
                seen.erase(s[left]);
                left++;
            }
        }
        return max;
    }
};