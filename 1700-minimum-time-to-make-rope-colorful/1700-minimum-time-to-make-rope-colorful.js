/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function (colors, neededTime) {
    let totalCost = 0;
    let n = colors.length;
    let groupStart = 0;

    while (groupStart < n) {
        let groupEnd = groupStart;
        let groupSum = 0;
        let maxTime = 0;

        while (groupEnd < n && colors[groupEnd] === colors[groupStart]) {
            groupSum += neededTime[groupEnd];
            maxTime = Math.max(maxTime, neededTime[groupEnd]);
            groupEnd++;
        }

        if (groupEnd - groupStart > 1) {
            totalCost += groupSum - maxTime;
        }

        groupStart = groupEnd;
    }

    return totalCost;
};