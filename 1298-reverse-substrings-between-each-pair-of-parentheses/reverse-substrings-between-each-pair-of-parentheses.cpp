// class Solution {
// public:
//     string reverseParentheses(string s) {

//         int n = s.length();

//       stack<string> st;
// string curr = "";

//         for (int i = 0; i < n; i++) {

//             if (s[i] == '(') {
//                 st.push(curr);
//                 curr = "";
//             }

//             else if (s[i] == ')') {
//                 reverse(curr.begin(), curr.end());
//              string p = st.top();
//              st.pop();

//                 curr = p + curr;

//             }

//             else {
//                 curr += s[i];
//             }
//         }

//         return curr;
//     }
// };


class Solution {
public:
    string reverseParentheses(string s) {

        int n = s.length();

        vector<string> st;
        string curr = "";

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push_back(curr);
                curr = "";
            }

            else if (s[i] == ')') {

                reverse(curr.begin(), curr.end());

                string p = st.back();
                st.pop_back();

                curr = p + curr;
            }

            else {
                curr += s[i];
            }
        }

        return curr;
    }
};