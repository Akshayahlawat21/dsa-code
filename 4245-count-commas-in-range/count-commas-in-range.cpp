class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);

        int m  = s.length();

        if(m<4){
            return 0;
        }

        int count  = 0;

        for (int i = 1000; i <= n; i++) {
        count++;
    }

        return count ;


        
    }
};