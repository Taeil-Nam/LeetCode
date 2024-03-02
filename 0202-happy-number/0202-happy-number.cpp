class Solution
{
public:
    bool isHappy(int n)
    {
        int sum = 0;
        ::unordered_set<int> seen;
        while (sum != 1) // O(1)
        {
            sum = 0;
            for (; n != 0; n /= 10) // O(d), d = n의 자리수
            {
                sum += ::pow(n % 10, 2);
            }
            if (seen.count(sum) > 0)
            {
                return false;
            }
            seen.insert(sum);
            n = sum;
        }
        return true;
    }
};

// Time complexity = O(d), d = n의 자리수
// Space complexity = O(1)

/*
Approch

[variables]
- sum : n의 각 자리수들의 제곱의 합
- seen : 계산된 sum의 값들을 기록해두는 해시테이블

[logic]
- sum이 1이 될 때까지 아래 내용 반복
    - sum을 0으로 초기화
    - n의 각 자리수의 제곱의 합을 구한다
        - 구해진 sum이 이미 나왔을 경우 false 반환
    - 구해진 sum을 seen에 기록한다
    - 현재 sum값을 n에 대입한다
    - sum이 1인 경우 반복을 종료한다
- 반복 종료시 true 반환

[Time complexity]
1. while (sum != 1)
    - 처음 구해지는 sum 값의 자리수가 반복 횟수가 된다.
    - 1 <= n <= 2^31 - 1 이기 때문에 n의 최대 자리수는 10자리 수이다.
    - 10자리 수의 각 자리수가 최대값인 9라고 가정했을 때, 해당 sum 값은 9^9 * 10 = 810이다.
    - 810 이 맨 처음 sum 값의 최대값이 된다.
    - 해당 값의 자리수는 3자리 수이기 때문에, 해당 반복문은 최대 9^9 * 3 = 243번 반복된다.
    - 즉 O(243) 만큼 반복하므로, O(1)이다.
2. for (; n != 0; n /= 10)
    - n의 자리수(d) 만큼 반복하므로, n의 자리수에 따라 다르다.
- 결론 : O(1 * d) = O(d)

[Space complexity]
- seen에 저장해두는 최대 개수는 sum의 최대 개수이므로, 243 + 1이다. O(1)
*/
