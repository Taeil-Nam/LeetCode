class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        while (num != 0)
        {
            if (num >= 1000)
            {
                num -= 1000;
                result.push_back('M');
            }
            else if (num >= 900)
            {
                num -= 900;
                result.push_back('C');
                result.push_back('M');
            }
            else if (num >= 500)
            {
                num -= 500;
                result.push_back('D');
            }
            else if (num >= 400)
            {
                num -= 400;
                result.push_back('C');
                result.push_back('D');
            }
            else if (num >= 100)
            {
                num -= 100;
                result.push_back('C');
            }
            else if (num >= 90)
            {
                num -= 90;
                result.push_back('X');
                result.push_back('C');
            }
            else if (num >= 50)
            {
                num -= 50;
                result.push_back('L');
            }
            else if (num >= 40)
            {
                num -= 40;
                result.push_back('X');
                result.push_back('L');
            }
            else if (num >= 10)
            {
                num -= 10;
                result.push_back('X');
            }
            else if (num >= 9)
            {
                num -= 9;
                result.push_back('I');
                result.push_back('X');
            }
            else if (num >= 5)
            {
                num -= 5;
                result.push_back('V');
            }
            else if (num >= 4)
            {
                num -= 4;
                result.push_back('I');
                result.push_back('V');
            }
            else if (num >= 1)
            {
                num -= 1;
                result.push_back('I');
            }
        }
        return result;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)
