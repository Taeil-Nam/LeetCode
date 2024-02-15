class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0;
        int j = 0;
        vector<int> merge;

        while (i < nums1.size() && j < nums2.size()) // O(n)
        {
            if (nums1[i] < nums2[j])
            {
                merge.push_back(nums1[i]);
                i++;
            }
            else
            {
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) // O(n)
        {
            merge.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) // O(n)
        {
            merge.push_back(nums2[j]);
            j++;
        }

        if (merge.size() % 2 == 0)
        {
            return (merge[merge.size() / 2 - 1] + merge[merge.size() / 2]) / 2.0f;
        }
        else
        {
            return merge[merge.size() / 2];
        }
    }
};
// Time complexity = O(n)
// Space complexity = O(n)