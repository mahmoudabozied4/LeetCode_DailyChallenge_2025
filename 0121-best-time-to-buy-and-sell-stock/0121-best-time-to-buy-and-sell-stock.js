/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  let min = Number.MAX_SAFE_INTEGER;
  let ans = 0 ;
  for(let i of prices) {
    min = Math.min(min, i);
    ans = Math.max(ans, i - min);
    // console.log(ans)
  }
  return Math.max(ans , 0);
};