/**
 * @param {number[]} nums
 * @return {number}
 */
var intersection = function (nums1, nums2) {
    let a = new Map();
    for (let i = 0; i < nums1.length; i++) {
        const count = a.get(nums1[i]) || 0;
        a.set(nums1[i], count + 1);
    }
    let ans = new Array();
    for (let i = 0; i < nums2.length; i++) {
        const count = a.get(nums2[i]) || 0;
        if (count !== 0) {
            ans.push(nums2[i]);
            a.set(nums2[i], 0);
        }
    }
    return ans;
};