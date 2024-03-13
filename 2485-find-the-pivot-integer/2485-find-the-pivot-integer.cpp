class Solution
{
public:
    int pivotInteger(int n)
    {
        int x = n / 2;
        while (x <= n) // O(n)
        {
            int leftSum = 0;
            int rightSum = 0;
            for (int i = 1; i <= x; i++) leftSum += i; // O(n)
            for (int j = x; j <= n; j++) rightSum += j; // O(n)
            if (leftSum == rightSum) return x;
            else if (leftSum > rightSum) return -1;
            x++;
        }
        return -1;
    }
};

/*
[Variables]
- int x : pivot 숫자.
- int leftSum : 1부터 x까지의 합.
- int rightSum : x부터 n까지의 합.

[Logic]
- n을 2로 나눈 값을 x로 정한다.
- 1부터 x까지의 합과 x부터 n까지의 합을 구하고 비교한다.
    - 합이 같은 경우
        - x 반환.
    - 왼쪽 합이 더 큰 경우
        - -1 반환.
    - 오른쪽 합이 더 큰 경우
        - x를 1 올리고 다시 합을 구한다.
- -1 반환

[Complexity]
- Time complexity = O(n^2)
- Space complexity = O(1)
*/
