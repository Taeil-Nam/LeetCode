class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> res(N, 0);
        stack<pair<int, int>> st; // <val, index>
        for (int i = 0; i < temperatures.size(); i++){
            int val = temperatures[i];
            while (st.size() && st.top().first < val){
                int beforeIndex = st.top().second;
                res[beforeIndex] = i - beforeIndex;
                st.pop();
            }
            st.push({val, i});
        }
        return res;
    }
};
