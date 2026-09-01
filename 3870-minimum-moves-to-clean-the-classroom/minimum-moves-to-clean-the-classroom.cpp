class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int k = 0;

        // L ko bit index denge
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        int target = (1 << k) - 1;

        // best[r][c][mask] = maximum energy
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        queue<array<int, 4>> q;

        // r, c, energy, mask
        q.push({sr, sc, energy, 0});
        best[sr][sc][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, en, mask] = q.front();
                q.pop();

                if (mask == target)
                    return moves;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (en == 0)
                        continue;

                    int nen = en - 1;
                    int nmask = mask;

                    // L collect
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // R reset
                    if (classroom[nr][nc] == 'R') {
                        nen = energy;
                    }

                    // Already reached with >= energy
                    if (nen <= best[nr][nc][nmask])
                        continue;

                    best[nr][nc][nmask] = nen;

                    q.push({nr, nc, nen, nmask});
                }
            }

            moves++;
        }

        return -1;
    }
};