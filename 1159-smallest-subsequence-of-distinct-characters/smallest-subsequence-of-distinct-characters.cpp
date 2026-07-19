// class Solution {
// public:
//     string smallestSubsequence(string s) {
//         unordered_map<char, int> ct;
//         unordered_map<char, bool> vis; // ??

//         for (char ch : s) 
//             ct[ch]++;
        

//         stack<char> st;
//         for (char ch : s) {
//             ct[ch]--;
//         }
//         if (vis[ch])
//             continue;
//         while (!st.empty() && st.top() > ch && ct[st.top()] > 0) {

//             vis[st.top()] = false;
//             st.pop();
//         }

//         st.push(ch);
//         vis[ch] = true;
//     }

//     string ans = "";

//     while(!st.empty()){
//         ans += st.top();
//         st.pop();
//     }

//     reverse(ans.begin(), ans.end());

//     return ans;
// }
// }
// ;

class Solution {
public:
    string smallestSubsequence(string s) {

        unordered_map<char, int> freq;
        unordered_map<char, bool> vis;

        // Count frequency
        for (char ch : s)
            freq[ch]++;

        stack<char> st;

        for (char ch : s) {

            // Current character consume ho gaya
            freq[ch]--;

            // Agar already stack me hai to skip
            if (vis[ch])
                continue;

            // Jab tak stack ka top bada hai aur future me fir milega
            while (!st.empty() &&
                   st.top() > ch &&
                   freq[st.top()] > 0) {

                vis[st.top()] = false;
                st.pop();
            }

            st.push(ch);
            vis[ch] = true;
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};