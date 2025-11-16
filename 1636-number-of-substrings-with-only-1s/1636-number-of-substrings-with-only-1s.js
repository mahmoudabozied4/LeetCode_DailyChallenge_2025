/**
 * @param {string} s
 * @return {number}
 */
var numSub = function(s) {
    const M = 1000000007;
    let ans = 0 ; 
    let l = -1; // last zero 
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '0') l = i ;
        ans += i - l ;
        if (ans >= M) ans -=M;
    }
    return ans;
};