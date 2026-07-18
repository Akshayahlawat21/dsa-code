class Solution {
public:
    int findGCD(vector<int>& nums) { 

        int n = nums.size();

        int ans=0;

        sort( nums.begin(),nums.end());

        int i =0;
        int j = n-1;

     int g =   gcd(nums[i], nums[j]);

ans = g;
        return ans;

        
        
    }
};