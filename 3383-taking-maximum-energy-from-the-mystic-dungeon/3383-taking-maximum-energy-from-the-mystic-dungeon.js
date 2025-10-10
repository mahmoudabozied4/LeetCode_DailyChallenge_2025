/**
 * @param {number[]} energy
 * @param {number} k
 * @return {number}
 */
var maximumEnergy = function (energy, k) {
    const n = energy.length;
    const dp = new Array(n).fill(0);

    let ans = -1e9;
    for (let i = 0; i < n; i++) {
        if (i < k) {
            dp[i] = energy[i];
        } else {
            dp[i] = Math.max(dp[i - k] + energy[i], energy[i]);
        }
        if (i >= n - k) {
            ans = Math.max(ans, dp[i]);
        }
    }

    return ans;

};