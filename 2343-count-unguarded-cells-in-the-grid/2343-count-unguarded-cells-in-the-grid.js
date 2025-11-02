/**
 * @param {number} m - Number of rows in the grid
 * @param {number} n - Number of columns in the grid
 * @param {number[][]} guards - Array of guard positions [row, col]
 * @param {number[][]} walls - Array of wall positions [row, col]
 * @returns {number} Number of unguarded cells
 */
function countUnguarded(m, n, guards, walls) {
    // 0 = empty, 1 = guard, 2 = wall
    const grid = new Uint8Array(m * n);
    const idx = (r, c) => r * n + c;

    for (const [r, c] of guards) grid[idx(r, c)] = 1;
    for (const [r, c] of walls) grid[idx(r, c)] = 2;

    const seen = new Uint8Array(m * n);

    // Row sweeps: left->right and right->left
    for (let r = 0; r < m; r++) {
        // left to right
        let watching = 0;
        for (let c = 0; c < n; c++) {
            const k = idx(r, c);
            if (grid[k] === 2) {            // wall
                watching = 0;
            } else if (grid[k] === 1) {     // guard
                watching = 1;
            } else if (watching) {          // empty and in sight
                seen[k] = 1;
            }
        }
        // right to left
        watching = 0;
        for (let c = n - 1; c >= 0; c--) {
            const k = idx(r, c);
            if (grid[k] === 2) {
                watching = 0;
            } else if (grid[k] === 1) {
                watching = 1;
            } else if (watching) {
                seen[k] = 1;
            }
        }
    }

    // Column sweeps: top->bottom and bottom->top
    for (let c = 0; c < n; c++) {
        // top to bottom
        let watching = 0;
        for (let r = 0; r < m; r++) {
            const k = idx(r, c);
            if (grid[k] === 2) {
                watching = 0;
            } else if (grid[k] === 1) {
                watching = 1;
            } else if (watching) {
                seen[k] = 1;
            }
        }
        // bottom to top
        watching = 0;
        for (let r = m - 1; r >= 0; r--) {
            const k = idx(r, c);
            if (grid[k] === 2) {
                watching = 0;
            } else if (grid[k] === 1) {
                watching = 1;
            } else if (watching) {
                seen[k] = 1;
            }
        }
    }

    // Count unguarded empty cells
    let unguarded = 0;
    for (let r = 0; r < m; r++) {
        for (let c = 0; c < n; c++) {
            const k = idx(r, c);
            if (grid[k] === 0 && !seen[k]) unguarded++;
        }
    }
    return unguarded;
}
