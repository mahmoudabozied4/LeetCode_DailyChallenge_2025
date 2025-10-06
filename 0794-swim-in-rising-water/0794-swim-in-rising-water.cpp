class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>  pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int maxElev = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (row == n - 1 && col == n - 1) {
                return maxElev;
            }
            if (visited[row][col])
                continue;
            visited[row][col] = true;

            for (auto& [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    !visited[newRow][newCol]) {
                    int newMaxElev = max(maxElev, grid[newRow][newCol]);
                    pq.push({newMaxElev, newRow, newCol});
                }
            }
        }

        return -1;
    }
};