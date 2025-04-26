class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> maxHeap;
        int N = nums.size();

        for (int num : nums) maxHeap.push(num);
        for (int i = 1; i < N; i += 2){
            nums[i] = maxHeap.top();
            maxHeap.pop();
        }
        for (int i = 0; i < N; i += 2){
            nums[i] = maxHeap.top();
            maxHeap.pop();
        }
    }
};