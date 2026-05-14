class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {

            maxi = max(maxi, nums[i]);
        }

        if (maxi != n - 1)
            return false;
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {

            // invalid number
            if (nums[i] > maxi || nums[i] < 1)
                return false;

            freq[nums[i]]++;
        }

        for (int i = 1; i < maxi; i++) {
            if (freq[i] != 1)
                return false;
        }

        // maxi should occur twice
        if (freq[maxi] != 2)
            return false;

        return true;
    }
};