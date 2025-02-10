class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int N = nums.size();
        long long totalPairCnt = N * (N - 1) / 2;
        long long goodPairCnt = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < N; i++){
            goodPairCnt += freq[nums[i] - i];
            freq[nums[i] - i]++;
        }
        return totalPairCnt - goodPairCnt;
    }
};

/*
[Intuition]
- bad pairs 개수를 찾는 것보다, good pairs 개수를 찾고 total pairs에서 빼는게 더 쉬움.
- bad pair의 조건 : j - i != nums[j] - nums[i]
    - 식을 바꾸면 : nums[i] - i != nums[j] - j
    - good pair는 bad pair의 반대, 즉 : nums[i] - i == nums[j] - j

[Approch]
- nums[i] - i가 몇 번 나왔는지를 저장하는 hashMap freq 사용.
- nums의 요소들을 순회하면서, 현재까지 나온 good pair 개수 저장.
    goodPairCnt += freq[nums[i] - i];
    freq[nums[i] - i]++;
- 전체 pair 개수 - good pair 개수 반환. (즉, bad pair 개수 반환)
*/