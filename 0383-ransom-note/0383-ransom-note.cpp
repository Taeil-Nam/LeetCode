class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> alphabetHash;

        for (char c : magazine) // O(n)
        {
            alphabetHash[c]++;
        }
        for (char c : ransomNote) // O(n)
        {
            alphabetHash[c]--;
            if (alphabetHash[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Time complexity = O(n)
// Space complexity = O(1) (only use lowercase)