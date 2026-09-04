class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
          int n = nums.size();

        int maxo = INT_MIN;
        int mino = INT_MAX;

        for (int i = 0; i < n; i++) {

            int tt = nums[i];

            maxo = max(maxo, tt);

            mino = INT_MAX;

            for (int j = i; j < n; j++) {
                mino = min(mino, nums[j]);
            }

            int stable = maxo - mino;

            if (stable <= k)
                return i;
        }

        return -1;
        
    }
};