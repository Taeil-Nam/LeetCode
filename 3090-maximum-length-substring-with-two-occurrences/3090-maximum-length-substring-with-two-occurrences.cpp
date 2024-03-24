class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int left = 0;
        int right = 1;
        unordered_map<char, int> seen;
        int maxLength = 0;
        
        seen[s[left]]++;
        while (right < s.size())
        {
            seen[s[right]]++;
            if (seen[s[right]] > 2)
            {
                seen[s[left]]--;
                seen[s[right]]--;
                left++;
                continue;
            }
            maxLength = ::max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};

