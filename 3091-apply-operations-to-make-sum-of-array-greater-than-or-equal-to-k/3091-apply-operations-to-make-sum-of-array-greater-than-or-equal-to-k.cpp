class Solution
{
public:
    int minOperations(int k)
    {
        int minCount = k - 1;
        for (int i = 2; i <= k; i++)
        {
            int val = i - 1 + (k / i);
            if (k % i == 0)
                val--;
            minCount = ::min(val, minCount);
        }
        return minCount;
    }
};

 /*
[Problem]
- 양수 k와 숫자 배열이 [1]로 초기화 되어 있다.
- 숫자 배열의 합 >= k 가 될 수 있는 가장 적은 수의 동작 횟수를 반환.
- 수행할 수 있는 동작은 아래와 같다:
    - 배열의 특정 요소의 값을 1 올린다.
    - 배열의 특정 요소의 값을 배열의 맨 뒤에 추가한다.
    
[Approch]
- minCount = k - 1;
- i를 2부터 k까지 올린다.
    - i - 1 + (k / i)을 계산한다.
    - k % i == 0인 경우 1을 빼준다.
    - 계산 값과 minCount 중 더 작은 것을 minCount로 갱신한다.
- minCount를 반환한다.
k = 11
i = 2, 1 + 5 = 6.
i = 3, 2 + 3 = 5.
i = 4, 3 + 2 = 5.
i = 5, 4 + 2 = 6.

k = 6
i = 2, 1 + 3 = 4.
i = 3, 2 + 2 - 1 = 3.
i = 4, 3 + 1 = 4.
i = 5, 4 + 1 = 5.
*/
