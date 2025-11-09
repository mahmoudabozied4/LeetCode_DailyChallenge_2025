class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> prev(m, vector<int>(k + 1, INT_MIN));
        vector<vector<int>> cur(m, vector<int>(k + 1, INT_MIN));

        for (int i = 0; i < n; ++i) {
            fill(cur.begin(), cur.end(), vector<int>(k + 1, INT_MIN));
            for (int j = 0; j < m; ++j) {
                int w = (grid[i][j] >= 1);
                int s = grid[i][j];

                for (int c = w; c <= k; ++c) {
                    int ans = INT_MIN;
                    if (i > 0)
                        ans = max(ans, prev[j][c - w]);

                    if (j > 0)
                        ans = max(ans, cur[j - 1][c - w]);

                    if (i == 0 && j == 0 && c == w)
                        ans = max(ans, 0);

                    if (ans != INT_MIN)
                        cur[j][c] = max(cur[j][c], ans + s);
                }
            }
            prev.swap(cur);
        }

        int ans = *max_element(prev[m - 1].begin(), prev[m - 1].end());
        return ans == INT_MIN ? -1 : ans;
    }
};