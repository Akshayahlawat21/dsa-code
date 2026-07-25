class Solution {
public:
    int maxProduct(int n) {
        int largest = -1;
int secondLargest = -1;
int  pro;

while (n > 0) {
    int digit = n % 10;

    if (digit > largest) {
        secondLargest = largest;   // old largest becomes second largest
        largest = digit;
    }
    else if (digit > secondLargest) {
        secondLargest = digit;
    }

    n /= 10;
     pro = largest * secondLargest;
}

 return pro ;
        
    }
};