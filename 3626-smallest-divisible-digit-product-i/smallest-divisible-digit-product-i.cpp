class Solution {
public:
    int smallestNumber(int n, int t) {
        // int temp = n;

        // int p = 1;

        while (true) {
            // Step 1
           int  temp = n;
           int p = 1;

            // Step 2
            // Calculate product of digits
            while (temp > 0) {

                int digit = temp % 10;
                p *= digit;
                temp = temp / 10;
            }

            // Step 3
            if (p % t == 0 )
                return n;

            // Step 4
            n++;
        }

        
    }
};
