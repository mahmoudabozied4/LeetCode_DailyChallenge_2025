/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
  if (nums.length == 0) return 0;
  nums.sort((a, b) => a - b);
  let ans = 0, cur = 1;

  for (let i = 1; i < nums.length; i++) {
    if (nums[i] === nums[i - 1]) continue;
    if (nums[i] === nums[i - 1] + 1) {
      cur++;
    } else {
      ans = Math.max(ans, cur);
      cur = 1;
    }
  }
  return Math.max(ans, cur);
};