#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s) // O(n)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty() ||
                (c == ')' && st.top() != '(') ||
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '['))
                {
                    return false;
                }
                st.pop();
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)

/*
Approch

- 괄호들이 들어 있는 문자열을 하나씩 검사한다.
- 열린 괄호일 때
    - 스택에 푸쉬한다.
- 닫힌 괄호일 때
    - 스택이 비어있거나, 스택의 맨 위의 요소(top)가 짝이 맞는 열린 괄호가 아닌 경우 false를 반환한다.
    - 스택의 맨 위의 요소(top)가 짝이 맞는 열린 괄호일 경우 해당 요소를 스택에서 제거(pop)한다.
- 반복문 종료 후
    - 스택이 비어있는 경우, 짝이 맞는 괄호들이 들어왔음을 의미하므로 true를 반환한다.
    - 스택이 비어있지 않은 경우, 짝이 없는 열린 괄호가 남아있음을 의미하므로 false를 반환한다.
*/
