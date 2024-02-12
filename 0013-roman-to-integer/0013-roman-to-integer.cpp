class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romans;
        int result = 0;

        romans['I'] = 1;
        romans['V'] = 5;
        romans['X'] = 10;
        romans['L'] = 50;
        romans['C'] = 100;
        romans['D'] = 500;
        romans['M'] = 1000;
        for (int i = 0; i < s.length(); i++)
        {
            if (romans[s[i]] < romans[s[i + 1]])
            {
                result -= romans[s[i]]; // IV = (-1) + 5 = 4
            }
            else
            {
                result += romans[s[i]];
            }
        }
        return result;
    }
};