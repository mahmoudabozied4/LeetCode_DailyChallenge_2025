/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
  let ans = nums;
  for (let i = 1; i < nums.length; i++) {
    ans[i] += ans[i - 1]
  }
  return nums
};