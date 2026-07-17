// class Solution {
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n = nums.size();

//         vector<int> gcdes;
//         vector<int> ans;

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int g = gcd(nums[i], nums[j]);
//                 gcdes.push_back(g);
//             }
//         }

//         sort(gcdes.begin(), gcdes.end());

//         for (long long q : queries) {
//             ans.push_back(gcdes[q]);
//         }

//         return ans;

       
//     }
// };

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // countDiv[d] = numbers divisible by d
        vector<long long> countDiv(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                countDiv[d] += freq[multiple];
            }
        }

        // exact[d] = pairs having gcd exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            exact[d] = countDiv[d] * (countDiv[d] - 1) / 2;

            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        // prefix counts
        vector<long long> prefix(mx + 1, 0);

        for (int d = 1; d <= mx; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        vector<int> ans;

        for (long long q : queries) {

            // queries are 0-indexed
            q++;

            int gcdValue =
                lower_bound(prefix.begin(), prefix.end(), q) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};