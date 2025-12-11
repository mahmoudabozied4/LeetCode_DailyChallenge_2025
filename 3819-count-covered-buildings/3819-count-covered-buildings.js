/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
var countCoveredBuildings = function (n, buildings) {
    const rows = new Map(), cols = new Map();
    for (const [x, y] of buildings) {
        if (!rows.has(x)) rows.set(x, []);
        if (!cols.has(y)) cols.set(y, []);
        rows.get(x).push(y);
        cols.get(y).push(x);
    }

    for (const [r, ys] of rows) ys.sort((a, b) => a - b);
    for (const [c, xs] of cols) xs.sort((a, b) => a - b);

    let covered = 0;

    for (const [x, y] of buildings) {
        const ys = rows.get(x);
        const xs = cols.get(y);

        const posY = binarySearch(ys, y);
        const posX = binarySearch(xs, x);

        const hasLeft = posY > 0;
        const hasRight = posY < ys.length - 1;
        const hasUp = posX > 0;
        const hasDown = posX < xs.length - 1;

        if (hasLeft && hasRight && hasUp && hasDown) {
            covered++;
        }
    }

    return covered;
};

function binarySearch(arr, target) {
    let l = 0, r = arr.length - 1;
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        if (arr[mid] === target) return mid;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}