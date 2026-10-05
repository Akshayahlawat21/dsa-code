class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char ch : s) {
            if (ch == '(') {
                st.push(0);
            } else {
                int top = st.top(); st.pop();
                int A = max(2 * top, 1);
                int B = st.top(); st.pop();
                st.push(A + B);
            }
        }

        return st.top();
    }
        
    
};