// class Solution {
// public:
//     int search(vector<int>& nums, int target) {

//         int i = 0;
//         int j = nums.size() - 1;

//         while (i <= j) {

//             int mid = i + (j - i) / 2;

        
//             if (nums[mid] == target) {
//                 return mid;
//             }


//             if( nums[i]<= nums[mid]){
//                 if( nums[i]<= target && target < nums[mid]){
//                     j = mid -1;
//                 }
//                 else {
//                     i = mid+1;
//                 }
//             }

//             else{
//                 if( nums[mid] < target && target <= nums[j]){
//                     i = mid +1;
//                 }
//                 else {
//                     j = mid-1;
//                 }
//             }
//         }
//         return -1;

//     }
// };

     
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){

            int mid=lo+(hi-lo)/2;

            if(nums[mid]==target)return mid;
            
            if(nums[mid]<nums[hi]){
                if(target>nums[mid] && target<=nums[hi])lo=mid+1;
                else hi=mid-1;
            }
            else{
                if(target<nums[mid] && target>=nums[lo]){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
        }
        return -1;
    }
};

          