class Solution
{
public:
    string firstPalindrome(vector<string>& words)
    {
        for (string str : words) // O(n)
        {
            string reverseStr = str;
            reverse(reverseStr.begin(), reverseStr.end()); // O(n)
            if (str == reverseStr)
            {
                return str;
            }
        }
        return "";
    }
};

// Time complexity = O(n^2)
// Space complexity = O(1)