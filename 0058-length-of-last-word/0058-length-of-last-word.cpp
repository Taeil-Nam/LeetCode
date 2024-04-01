class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string res;
        while (ss >> res)
            ;
        return res.size();
    }
};
