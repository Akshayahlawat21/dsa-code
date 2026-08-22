class Solution {
public:
    bool checkDivisibility(int n) {

        int temp = n ;

        int product =1;

        int sum =0;

        while( temp!= 0){
            int dig = temp%10;
            sum += dig;
            temp /=10;

        }
           temp = n;

        while(temp!=0){
            int digi= temp%10;
            product = product* digi;
            temp /=10;
        }
        int f = sum + product;
     if (n % f == 0) {
    return true;
}
      return false;

    }
};