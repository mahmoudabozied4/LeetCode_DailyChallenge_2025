/**
 * @param {number[]} nums
 * @param {number} original
 * @return {number}
 */
var findFinalValue = function(nums, original) {
    let a = Array(1001);
    for (let i = 0; i < nums.length; i++) {
        a[nums[i]] = 1;
    }
    while (a[original] === 1) original*=2;
    return original;
};