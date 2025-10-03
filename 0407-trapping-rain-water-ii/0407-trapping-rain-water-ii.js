/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    const m = heightMap.length;
    const n = heightMap[0].length;
    if (m <= 2 || n <= 2) return 0;

    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const heap = [];
    const directions = [ [0,1], [0,-1], [1,0], [-1,0] ];
    let water = 0;

    // Add the boundaries to the heap
    for (let i = 0; i < m; i++) {
        heap.push([heightMap[i][0], i, 0]);
        heap.push([heightMap[i][n - 1], i, n - 1]);
        visited[i][0] = true;
        visited[i][n - 1] = true;
    }
    for (let j = 1; j < n - 1; j++) {
        heap.push([heightMap[0][j], 0, j]);
        heap.push([heightMap[m - 1][j], m - 1, j]);
        visited[0][j] = true;
        visited[m - 1][j] = true;
    }

    // Implement Heap as a min heap using push and sort
    heap.sort((a,b) => a[0] - b[0]);

    while (heap.length > 0) {
        // Poll the lowest cell
        const curr = heap.shift();
        const height = curr[0];
        const x = curr[1];
        const y = curr[2];

        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                water += Math.max(0, height - heightMap[nx][ny]);
                heap.push([ Math.max(heightMap[nx][ny], height), nx, ny ]);
                heap.sort((a,b) => a[0] - b[0]);
            }
        }
    }
    return water;
};
