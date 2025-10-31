/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function(nums) {
    const ans = [] ;
    const mp = new Map();
    for (const num of nums) {
        const count = mp.get(num) || 0;
        mp.set(num, count + 1);
        if (count > 0) {
            ans.push(num);
        }
    }
    return ans;
};