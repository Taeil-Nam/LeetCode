class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> seen;
        unordered_set<int> use;
        for (int num : nums1) // O(n)
        {
            seen[num]++;
        }
        vector<int> result;
        for (int num : nums2) // O(n)
        {
            if (seen[num] > 0 && use.count(num) == 0)
            {
                result.push_back(num);
                use.insert(num);
            }
        }
        return result;
    }
};

/*
Approch
[Variables]
- unordered_map<int, int> seen : nums1에 저장된 숫자들을 기록.
- unordered_set<int> use : nums2에서 result에 추가한 숫자들을 기록.

[Logic]
- nums1을 순회하면서 seen에 기록한다. seen[num]++;
- nums2를 순회하면서 seen에 해당 숫자가 있고 use에 기록되지 않았다면, result와 use에 숫자를 추가한다.
- result를 반환한다.
*/
