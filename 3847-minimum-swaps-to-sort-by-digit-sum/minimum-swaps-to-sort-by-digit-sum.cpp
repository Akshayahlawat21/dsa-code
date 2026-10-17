
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> vt;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int sum = 0;

            while (temp > 0) {
                int d = temp % 10;
                sum += d;
                temp = temp / 10;
            }

            vt.push_back({sum, nums[i]});
        }

        sort(vt.begin(), vt.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[vt[i].second] == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[vt[j].second];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
