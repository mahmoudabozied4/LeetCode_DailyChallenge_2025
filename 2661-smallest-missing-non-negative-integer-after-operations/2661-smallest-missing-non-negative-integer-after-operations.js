/**
 * @param {number[]} nums
 * @param {number} value
 * @return {number}
 */
var findSmallestInteger = function(nums, value) {
    const remainderCount  = new Array(value).fill(0);

    for (const num of nums) {
        const remainder = ((num % value) + value) % value;
        remainderCount[remainder]++;

    }
    for (let candidate = 0; ; candidate++) {
        const remainderClass = candidate % value;
        if (remainderCount[remainderClass] === 0) {
            return candidate;
        }
        remainderCount[remainderClass]--;
    }
    return 0;
};