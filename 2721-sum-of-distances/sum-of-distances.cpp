class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        int n = nums.size();
        vector<long long> arr(n, 0);

        unordered_map<int, vector<int>> mp;

        // Step 1: store indices
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for(auto &it : mp){
            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> prefix(m, 0);

            // build prefix sum
            prefix[0] = v[0];
            for(int i = 1; i < m; i++){
                prefix[i] = prefix[i-1] + v[i];
            }

            for(int i = 0; i < m; i++){

                // left side
                long long left = (long long)v[i] * i - (i > 0 ? prefix[i-1] : 0);

                // right side
                long long right = (prefix[m-1] - prefix[i]) - (long long)v[i] * (m - i - 1);

                arr[v[i]] = left + right;
            }
        }

        return arr;
    }
};