class Solution {
public:
    string smallestPalindrome(string s) {

           int n = s.length();

        // Take the first half
        string half = s.substr(0, n / 2);

        // Sort the first half
        sort(half.begin(), half.end());

        // Build the result
        string res = half;

        // Add the middle character if the length is odd
        if (n % 2 == 1) {
            res += s[n / 2];
        }

        // Reverse the first half and append it
        string rev = half;
        reverse(rev.begin(), rev.end());
        res += rev;

        return res;
        
        
    }
};