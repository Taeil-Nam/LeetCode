class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        1.  nums의 요소들을 unordered_set으로 저장.
            - 요소 중복을 처리하여 없애줌.
            - hash map 기반이므로 요소 삽입 = O(1).
        2.  nums를 순회하면서 각 요소가 연속 수열의 시작 부분인지 확인.
            - 현재 숫자 - 1 값이 unordered_set에 없으면 연속 수열의 시작 숫자로 판단.
        3.  연속 수열의 시작 부분인 경우, 연속 수열의 길이를 구한 뒤 최대 길이인 경우 해당 값으로 결과 갱신.
            - res = max(res, len);
        */        
        unordered_set<int> seen(nums.begin(), nums.end());
        int res = 0;

        for (int num : nums){
            if (seen.count(num - 1)) continue;
            
            int curr = num;
            int len = 0;
            while (seen.count(curr)){
                curr++;
                len++;
            }
            res = max(res, len);
        }
        return res;
    }
};