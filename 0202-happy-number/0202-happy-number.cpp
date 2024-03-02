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
// Space complexity = O(d)

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
*/
