class Solution {
public:
    int reverseDegree(string s) {
        
        int n  = s.size();
        int sum = 0;

         for( int  i = 0;i<n;i++){
             char ch = s[i];

              int al = ch - 'a'+1;
              int rev  = 27- al;
              int pos  = i+1;
              int prod = rev * pos;

              sum += prod;
             
         }

         return sum; 
        
    }
};