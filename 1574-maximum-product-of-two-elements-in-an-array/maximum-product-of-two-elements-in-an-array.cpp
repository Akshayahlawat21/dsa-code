// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {

//         int n = nums.size();

//         int ans =0;

//           sort(nums.begin(), nums.end());

//           int a  = nums[n-1];
//            int  x = a-1;
//           int b = nums[n-2];
//           int  y  = b-1;

//                 ans = x * y ;
//           return ans ;

//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};