/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxDistinctElements = function(nums, k) {
    nums.sort((a, b) => a - b);
    let distinctCount = 0;
    let previousValue = -Infinity;
    
    for (const currentNum of nums) {
        const lowerBound = Math.max(currentNum - k, previousValue + 1);
        if (lowerBound <= currentNum + k) {
            distinctCount++;
            previousValue = lowerBound;
        }
    }
    
    return distinctCount;
};