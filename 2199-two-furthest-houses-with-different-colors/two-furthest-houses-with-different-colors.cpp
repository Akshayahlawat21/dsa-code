class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int d = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]) {
                    ans = abs(i - j);
                    d = max(ans, d);
                }
            }
        }

        return d;
    }
};