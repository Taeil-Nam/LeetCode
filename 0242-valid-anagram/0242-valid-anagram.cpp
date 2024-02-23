class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> seen;
        if (s.length() != t.length())
        {
            return false;
        }
        for (char c : t) // O(n)
        {
            seen[c]++;
        }
        for (char c : s) // O(n)
        {
            seen[c]--;
            if (seen[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)