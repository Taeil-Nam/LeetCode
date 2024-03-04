class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int countOne = 0;
        for (char c : s) // O(n)
        {
            if (c == '1')
            {
                countOne++;
            }
        }
        string result;
        for (int i = 0; i < s.size() - 1; i++) // O(n)
        {
            if (countOne > 1)
            {
                result.push_back('1');
                countOne--;
            }
            else
            {
                result.push_back('0');
            }
        }
        result.push_back('1');
        return result;
    }
};

/*
Approch
[Variables]
- int countOne : 1이 몇번 나왔는지 저장하는 변수
- string result : 결과값을 저장하는 문자열

[Logics]
- 1이 몇번 나왔는지 카운트 후 countOne에 저장한다.
- s의 크기만큼 아래 과정을 반복한다.
    - countOne이 1보다 크면 result에 1을 넣고 countOne을 1 줄인다.
    - countOne이 1보다 작거나 같으면 result에 0을 넣는다.
- result에 1을 추가한다.
- result를 반환한다.
*/
