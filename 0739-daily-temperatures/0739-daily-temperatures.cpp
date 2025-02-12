class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> res(N, 0);
        stack<pair<int, int>> st; // <val, index>?
        for (int i = 0; i < temperatures.size(); i++){
            int val = temperatures[i];
            if (st.size()){
                int currentIndex = i;
                while (st.size() && st.top().first < val){
                    int beforeIndex = st.top().second;
                    res[beforeIndex] = currentIndex - beforeIndex;
                    st.pop();
                }
            }
            st.push({val, i});
        }
        while (st.size()){
            res[st.top().second] = 0;
            st.pop();
        }
        return res;
    }
};
/*
idx          0  1  2  3  4  5  6
tempers     [30,38,30,36,35,40,28]
valStack    [40,28]
idxStack    [5,6]
res         [1,4,1,2,1,0,0]
*/