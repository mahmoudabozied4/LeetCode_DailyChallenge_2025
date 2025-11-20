/**
 * @param {number[][]} intervals
 * @return {number}
 */
var intersectionSizeTwo = function(intervals) {
    intervals.sort((a, b) => {
        if (a[1] === b[1]) {
            return b[0] - a[0];
        }
        return a[1] - b[1];
    });

    let result = 0;

    let secondLastPoint = -1;
    let lastPoint = -1;

    for (const [s, e] of intervals) {
        if (s <= secondLastPoint) {
            continue;
        }
        if (s > lastPoint) {
            result += 2;
            secondLastPoint = e - 1;
            lastPoint = e;
        }
        else {
            result += 1;
            secondLastPoint = lastPoint;
            lastPoint = e;
        }
    }

    return result;
};