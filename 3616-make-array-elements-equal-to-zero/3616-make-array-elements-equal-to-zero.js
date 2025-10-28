/**
 * @param {number[]} nums
 * @return {number}
 */
var countValidSelections = function (nums) {
    let ans = 0;
    let prefix = 0;
    let suffix = nums.reduce((acc, val) => acc + val, 0);

    for (let i = 0; i < nums.length; ++i) {
        suffix -= nums[i];
        prefix += nums[i];
        if (nums[i] > 0) {
            continue;
        }
        if (prefix === suffix) {
            ans += 2;
        }
        if (Math.abs(prefix - suffix) === 1) {
            ans += 1;
        }
    }

    return ans;
};