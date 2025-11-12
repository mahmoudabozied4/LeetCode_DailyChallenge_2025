/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    const n = nums.length;

    const gcd = (a, b) => {
        while (b !== 0) {
            [a, b] = [b, a % b];
        }
        return a;
    };
    let g = nums[0];
    for (let i = 1; i < n; i++) {
        g = gcd(g, nums[i]);
    }
    if (g > 1) return -1;

    const ones = nums.filter(x => x === 1).length;
    if (ones > 0) return n - ones;

    let minLen = Infinity;
    for (let i = 0; i < n; i++) {
        let currentGcd = nums[i];
        for (let j = i + 1; j < n; j++) {
            currentGcd = gcd(currentGcd, nums[j]);
            if (currentGcd === 1) {
                minLen = Math.min(minLen, j - i + 1);
                break;
            }
        }
    }

    return (minLen - 1) + (n - 1);
    
};