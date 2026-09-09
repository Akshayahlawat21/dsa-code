#define ll long long
class Solution {
public:
    long long countCommas(long long n) {

        ll total= 0;
        ll threshold = 1000;

        while( threshold <= n){
            total +=  n -threshold+1;

            if( threshold > n/1000){
                break;
            }

            threshold*=1000;
        }

         return total;
        
    }
};