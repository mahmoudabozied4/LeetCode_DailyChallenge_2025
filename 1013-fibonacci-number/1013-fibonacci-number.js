/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    let dp = new Array(n + 1);
    if( n === 0) return 0;
    dp[0] = 0 , dp[1] = 1;
    for(var i = 2; i <= n; i++)  dp[i] = dp[i - 2] + dp[i-1];
    return dp[n];
};