class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxvar =  0;

        for( int i =0;i<n; i++){

            if(i > maxvar) return false;

            maxvar = max(maxvar , i + nums[i]);
        }

         return true;
        
    }
};