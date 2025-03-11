class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens){
            if (token == "+"){
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(l + r);
            }
            else if (token == "-"){
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(l - r);
            }
            else if (token == "*"){
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(l * r);
            }
            else if (token == "/"){
                int r = st.top();
                st.pop();
                int l = st.top();
                st.pop();
                st.push(l / r);
            }
            else
                st.push(stoi(token));
        }
        return st.top();
    }
};