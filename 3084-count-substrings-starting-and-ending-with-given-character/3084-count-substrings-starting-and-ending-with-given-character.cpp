class Solution
{
public:
    long long countSubstrings(string s, char c)
    {
        long long n = 0;
        for (char ch : s)
        {
            if (ch == c) n++;
        }
        long long sum = n * (n + 1) / 2;
        return sum;
    }
};

/*
Approch

[Variables]
- long long n : 문자열 s에 문자 c가 나온 횟수.

[Logic]
- 문자열 s를 순회하면서 c가 나온 경우 n을 1 올린다.
- n(n + 1) / 2 = n개의 c로 만들 수 있는 subArray의 개수이다.
- sum = n(n + 1) / 2
- sum 반환.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/
