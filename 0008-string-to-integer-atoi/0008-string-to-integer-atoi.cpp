class Solution 
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        int i = 0;
        long long result = 0;
        while (::isspace(s[i])) i++; // O(n)
        if (s[i] == '+' || s[i] == '-')
        {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (::isdigit(s[i])) // O(n)
        {
            result *= 10;
            result = result + s[i] - '0';
            if (sign * result < INT_MIN) return INT_MIN;
            else if (sign * result > INT_MAX) return INT_MAX;
            i++;
        }
        return sign * result;
    }
};

/*
Approch
[Variables]
- int sign : 부호 판별.
- int i : 문자열의 현재 인덱스.
- long long result : 결과 숫자.

[Logic]
- 맨 앞의 white space들을 생략한다.
- sign 부호를 판별한다.
- 현재 문자가 숫자인 경우 아래 내용을 반복한다.
    - result에 10을 곱하고, 현재 숫자를 더한다.
    - sign * result의 값이 INT 범위를 벗어나는지 확인한다.
        - INT_MIN 보다 작은 경우 INT_MIN 반환.
        - INT_MAX 보다 큰 경우 INT_MAX 반환.
    - i를 1 증가시킨다.
- sign * result를 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/
