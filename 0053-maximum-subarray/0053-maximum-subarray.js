/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    function maxSubarraySum(arr) {
        // Kadane's Algorithm
        let res = arr[0];
        let maxEnding = arr[0];

        for (let i = 1; i < arr.length; i++) {
            maxEnding = Math.max(maxEnding + arr[i], arr[i]);
            res = Math.max(res, maxEnding);
        }
        return res;
    }
    return maxSubarraySum(nums);
};