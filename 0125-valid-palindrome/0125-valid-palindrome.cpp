#include <cctype>

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left <= right)
        {
            if (isalnum(s[left]) == false)
            {
                left++;
                continue;
            }
            if (isalnum(s[right]) == false)
            {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};