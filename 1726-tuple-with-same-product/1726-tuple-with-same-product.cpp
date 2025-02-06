class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        unordered_map<int, int> productCnt;
        for (int i = 0; i < N - 1; i++){
            for (int j = i + 1; j < N; j++){
                int product = nums[i] * nums[j];
                productCnt[product]++;
                if (productCnt[product] >= 2)
                    res += (productCnt[product] - 1) * 8;
            }
        }
        return res;
    }
};

/*
[Intuition]
a * b = c * d를 만족하는 (a, b) (c, d) pair가 있을 때,
두 pair로 만들 수 있는 모든 tuple은 8개 이다.
(a, b, c, d), (a, b, d, c), (b, a, c, d), (b, a, d, c)
(c, d, a, b), (c, d, b, a), (d, c, a, b), (d, c, b, a).

pair가 3개 : 만들 수 있는 tuple의 개수는 24개,
pair가 4개 : 만들 수 있는 tuple의 개수는 48개.
즉, pair가 N개 : (N(N - 1) / 2) * 8개의 튜플을 만들 수 있다.

[Approach]
- 만들 수 있는 모든 pair를 구하고, 해당 pair의 곱이 나올 때마다 count를 1 올린다.
- count가 2 이상이 되었을 때부터 tuple을 만들 수 있게되므로,
  값이 2일 때부터 (N - 1) * 8을 결과 값에 더한다.
- 결과 반환.
*/