class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
            vector<vector<int> > prefix(n, vector<int>(n + 1));

    for (auto &query: queries) {
        int r1 = query[0], c1 = query[1];
        int r2 = query[2], c2 = query[3];
        for (int i = r1; i <= r2; ++i) {
            ++prefix[i][c1];
            --prefix[i][c2 + 1];
        }
    }
    vector<vector<int> > ans(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += prefix[i][j];
            ans[i][j] = sum;
        }
    }

    return ans;
    }
};