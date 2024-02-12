class Solution
{
public:
    bool isPalindrome(int x)
    {
        stringstream ss;
        string numberStr;

        ss << x;
        ss >> numberStr;

        int i = 0;
        int j = numberStr.length() - 1;
        for (; i <= (int)(numberStr.length() / 2 - 1); i++, j--)
        {
            if (numberStr[i] != numberStr[j])
            {
                return false;
            }
        }
        return true;
    }
};