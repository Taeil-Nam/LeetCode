class Solution
{
public:
    string customSortString(string order, string s)
    {
        string result;
        for (char c : order) // O(n)
        {
            size_t target = s.find(c); // O(n)
            if (target == string::npos) continue;
            else
            {
                while (target != string::npos) // O(n)
                {
                    result.push_back(c);
                    s.erase(target, 1); // O(n)
                    target = s.find(c); // O(n)
                }
            }
        }
        result.append(s); // O(n)
        return result;
    }
};

/*
Approch
[Variables]
- string result : 문제 요구에 맞게 만들어진 문자열.
- size_t target : s에 order의 글자가 위치한 인덱스.

[Logic]
- order의 글자들을 탐색하면서 아래 내용을 반복한다.
    - order의 글자가 s에 있는지 찾는다.
    - s에 해당 글자가 있으면, 해당 글자가 s에 있을 때까지 아래 내용을 반복한다.
        - result에 해당 글자를 추가한다.
        - s에서 해당 글자를 삭제한다.
    - s에 해당 글자가 없으면 다음 글자로 넘어간다.
- result에 남은 s를 더한다.
- result를 반환한다.

[Complexity]
- Time complexity = O(n^2)
- Space complexity = O(n)
*/
