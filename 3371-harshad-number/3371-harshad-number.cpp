class Solution
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        /*
        [문제]
        - hash number = (숫자 / 각 자릿수의 합)으로 나누어 떨어질 수 있는 수
        - hash number면 각 자릿수의 합을 return
        - 아니면 -1 return
        */
        int sum = 0;
        int tempNum = x;
        while (tempNum != 0)
        {
            sum += tempNum % 10;
            tempNum /= 10;
        }
        if (x % sum == 0)
            return sum;
        return -1;
    }
};