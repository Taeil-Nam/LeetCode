class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < strs.size(); i++) // O(n)
        {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        vector<vector<string> > result;
        for (auto value : m) // O(n)
        {
            result.push_back(value.second);
        }
        return result;
    }

private:
    string getKey(string str)
    {
        string key;
        vector<int> count(26, 0);
        for (char c : str) // O(n)
        {
            count[c - 'a']++;
        }
        for (int i = 0; i < count.size(); i++) // O(1)
        {
            key.append(to_string(count[i]) + "#");
        }
        return key;
    }
};

// Time complexity = O(n^2)
// Space complexity = O(n^2)