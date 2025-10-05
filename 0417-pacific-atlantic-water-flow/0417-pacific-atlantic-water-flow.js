/**
 * @param {number[][]} heights
 * @return {number[][]}
 */

var pacificAtlantic = function (heights) {
    function dfs(i, j, prev, ocean) {
    if (i < 0 || i >= numRows || j < 0 || j >= numCols || heights[i][j] < prev || ocean[i][j]) {
        return;
    }
    ocean[i][j] = true;

    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    for (const [di, dj] of directions) {
        dfs(i + di, j + dj, heights[i][j], ocean);
    }
}
    const numRows = heights.length;
    const numCols = heights[0].length;
    const pacific = Array(numRows).fill().map(() => Array(numCols).fill(false));
    const atlantic = Array(numRows).fill().map(() => Array(numCols).fill(false));

    for (let col = 0; col < numCols; col++) {
        dfs(0, col, -Infinity, pacific);
        dfs(numRows - 1, col, -Infinity, atlantic);
    }
    for (let row = 0; row < numRows; row++) {
        dfs(row, 0, -Infinity, pacific);
        dfs(row, numCols - 1, -Infinity, atlantic);
    }

    const res = [];
    for (let i = 0; i < numRows; i++) {
        for (let j = 0; j < numCols; j++) {
            if (atlantic[i][j] && pacific[i][j]) {
                res.push([i, j]);
            }
        }
    }
    return res;
};