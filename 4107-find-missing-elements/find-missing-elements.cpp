class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

         int n = nums.size();
         sort(nums.begin(),nums.end());

         vector<int> ans;

       
          for (int i = 0; i < n - 1; i++) {
    for (int x = nums[i] + 1; x < nums[i + 1]; x++) {
        ans.push_back(x);
    }
}
         return ans ;
    }
};