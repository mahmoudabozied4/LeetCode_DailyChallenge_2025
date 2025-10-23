/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function (s) {
    let maxNestingDepth = 0, currentDepth = 0;
    for (const ch of s) {
        if (ch === '(') {
            currentDepth++;
            maxNestingDepth = Math.max(maxNestingDepth, currentDepth);
        } else if (ch === ')') {
            currentDepth--;
        }
    }
    return maxNestingDepth;
};