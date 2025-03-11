class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < N; i++){
            int start = i;
            while (st.size() && st.top().second > heights[i]){
                maxArea = max(maxArea, (i - st.top().first) * st.top().second);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while (st.size()){
            maxArea = max(maxArea, (N - st.top().first) * st.top().second);
            st.pop();
        }
        return maxArea;
    }
};