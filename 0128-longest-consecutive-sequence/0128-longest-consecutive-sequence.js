/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
    // Have Every Start & Work On It
    const st = new Set(nums);
    let ans = 0;

    for (const num of st) {
        if (!st.has(num - 1)) {
            let curNum = num, cur = 1;

            while (st.has(curNum + 1)) {
                curNum++;
                cur++;
            }

            ans = Math.max(ans, cur);
        }
    }
    return ans;
};