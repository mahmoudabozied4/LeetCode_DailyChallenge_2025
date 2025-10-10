/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
  let ans = 0
  for (let account of accounts) {
    let cur = 0
    for (let num of account) {
      cur += num
    }
    ans = Math.max(ans, cur)
  }
  return ans
};