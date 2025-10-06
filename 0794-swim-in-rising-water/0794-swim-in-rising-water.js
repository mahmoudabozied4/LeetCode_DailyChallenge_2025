/**
 * @param {number[][]} grid
 * @return {number}
 */
var swimInWater = function(grid) {
    const n = grid.length;
    const heap = [[grid[0][0], 0, 0]];
    const visited = new Set();
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    while (heap.length > 0) {
        heap.sort((a, b) => a[0] - b[0]);
        const [maxElev, row, col] = heap.shift();
        
        if (row === n - 1 && col === n - 1) {
            return maxElev;
        }
        
        const key = `${row},${col}`;
        if (visited.has(key)) continue;
        
        visited.add(key);
        
        for (const [dr, dc] of directions) {
            const newRow = row + dr;
            const newCol = col + dc;
            const newKey = `${newRow},${newCol}`;
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                !visited.has(newKey)) {
                const newMaxElev = Math.max(maxElev, grid[newRow][newCol]);
                heap.push([newMaxElev, newRow, newCol]);
            }
        }
    }
    
    return -1;
};