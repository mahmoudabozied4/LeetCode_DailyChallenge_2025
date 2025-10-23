/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    const ans = [];
    let i = 0;    
    let num = 1;  
    while (i < target.length && num <= n) {
        if (target[i] === num) {
            ans.push("Push");
            i++;
        } else {
            ans.push("Push", "Pop");
        }
        num++;
    }
    return ans;
};