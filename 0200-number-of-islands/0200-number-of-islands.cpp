
class Solution {
    void dfs(vector<vector<char>>& grid, int row, int column) {
        int number_of_rows = grid.size();
        int number_of_columns = grid[0].size();
        if (row < 0 || row >= number_of_rows || column < 0 || column >= number_of_columns || grid[row][column] == '0') {
            return;
        }
        grid[row][column] = '0';
        dfs(grid, row + 1, column);
        dfs(grid, row - 1, column);
        dfs(grid, row, column + 1);
        dfs(grid, row, column - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));

        int ans = 0 ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] and grid[i][j] == '1') {
                    dfs(grid , i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
