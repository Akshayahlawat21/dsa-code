class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixgd(n);
        long long ans = 0;

        int mxi = 0;

        for (int i = 0; i < n; i++) {
            mxi = max(mxi, nums[i]);
            prefixgd[i] = gcd(nums[i], mxi);
        }
        sort(prefixgd.begin(), prefixgd.end());
        int i = 0;
        int j = n - 1;

        while (i < j) {
            ans += gcd(prefixgd[i], prefixgd[j]);
            i++;
            j--;
        }

        return ans;
    }
};