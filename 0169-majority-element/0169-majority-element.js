/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let a = new Map();
    for (let i = 0; i < nums.length; i++) {
        // Get the current count (or 0 if it doesn't exist), then add 1
        const count = a.get(nums[i]) || 0;
        a.set(nums[i], count + 1);
    }

    // console.log(a);
    let ans;
    let cnt = 0;

    for (const [key, value] of a) {
        if (cnt < value) {
            cnt = value;
            ans = key;
        }
    }

    return ans;
};