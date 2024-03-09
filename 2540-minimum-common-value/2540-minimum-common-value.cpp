class Solution
{
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) // O(n)
        {
            if (nums1[i] == nums2[j])
            {
                return nums1[i];
            }
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return -1;
    }
};

/*
Approch
[Variables]
- int i : nums1의 인덱스.
- int j : nums2의 인덱스.

[Logic]
- i가 nums1의 size보다 작고, j가 nums2의 size보다 작으면 아래 내용을 반복한다.
    - nums1[i] == nums2[j]인 경우 해당 값을 반환한다.
    - nums1[i] < nums2[j]인 경우 i를 1 올린다.
    - nums2[i] > nums2[j]인 경우 j를 1 올린다.
- 반복이 종료된 경우, 공통 수가 없으므로 -1을 반환한다.

[Complexity]
- Time complexity = O(n)
- Space complexity = O(1)
*/
