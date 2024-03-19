class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> record;
        unordered_map<char, int> mapCount;
        for (int i = 0; i < s.size(); i++) // O(n)
        {
            if (record[s[i]] == 0)
            {
                if (mapCount[t[i]] != 0)
                    return false;
                else
                {
                    record[s[i]] = t[i];
                    mapCount[t[i]]++;
                }
            }
            else
            {
                if (record[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

/*
Approch

[Variables]
- unordered_map<char, char> record : s의 문자가 매핑되었는지 기록.
- unordered_map<char, int> mapCount : t의 문자에 매핑된 문자가 있는지 기록.

[Logic]
- 문자열 s의 문자를 순회하면서 아래 내용을 반복한다:
    - s[i]가 매핑된 적이 없는 경우
        - t[i]에 매핑된 문자가 이미 존재하는 경우
            - return false;
        - t[i]에 매핑된 문자가 존재하지 않는 경우
            - s[i]를 t[i]로 매핑한다.
            - t[i]에 매핑된 문자가 있음을 기록한다.
    - s[i]가 매핑된 적이 있는 경우
        - 이전에 매핑된 문자가 t[i]와 다른 경우
            - return false;
- return true;

[Complexity]
- Time complexity = O(n)
- Space complexity = O(n)
*/
