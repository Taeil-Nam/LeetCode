class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s){
            if (c == ')' || c == '}' || c == ']'){
                if (st.empty() ||
                    c == ')' && st.top() != '(' ||
                    c == '}' && st.top() != '{' ||
                    c == ']' && st.top() != '[')
                    return false;
                else
                    st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};
