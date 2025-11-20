class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        stack<int> st;
        vector<int> res(N, 0);

        for (int i = 0; i < N; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int start = st.top();
                res[start] = i - start;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};