class Solution {
public:
    int numDistinct(string s, string t) {
       int n = s.length(); // String s ki length
        int m = t.length(); // String t ki length

        // Agar main string choti hai target se, toh match banna namumkin hai
        if (n < m) return 0; 

        // 1. Matrix Size Fix: Rows = n+1, Columns = m+1
        // Data type: unsigned long long (Overflow se bachne ke liye)
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // 2. Base Case Fix: Jab target string 't' khatam ho jaye (j == m)
        // Toh hume 1 valid subsequence mil gayi hai
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        // 3. Nested Loops
        for (int i = n - 1; i >= 0; i--) {
            char schar = s.at(i);
            for (int j = m - 1; j >= 0; j--) {
                char tcar = t.at(j);
                
                if (schar == tcar) {
                    // Ab yeh bilkul safe hai aur overflow nahi karega
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        // Final Answer hamesha integer range mein hi fit baithta hai
        return (int)dp[0][0];
        
    }
};