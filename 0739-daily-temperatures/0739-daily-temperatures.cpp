class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++){
            int val = temperatures[i];
            while (st.size() && st.top().first < val){
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({val, i});
        }
        return res;
    }
};

/*
idx: 6  7
st : 76 73
res: 1 1 4 2 1 1 0 0
*/