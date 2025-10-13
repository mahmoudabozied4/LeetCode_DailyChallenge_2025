/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let left = 0
    let ans = 0
    let mp = new Map();
    for (let right = 0; right < s.length; right++) {
        if (mp.has(s[right]) && mp.get(s[right]) >= left) {
            left = mp.get(s[right])  + 1;
        }
        mp.set(s[right], right);
        ans = Math.max(ans, right - left + 1);
    }
    return ans;
};