class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < heights.size(); i++){
            int start = i;
            while (st.size() && st.top().second > heights[i]){
                res = max(res, (i - st.top().first) * st.top().second);
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while (st.size()){
            res = max(res, (int)(heights.size() - st.top().first) * st.top().second);
            st.pop();
        }
        return res;
    }
};