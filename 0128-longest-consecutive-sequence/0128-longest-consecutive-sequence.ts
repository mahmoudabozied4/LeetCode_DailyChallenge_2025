function longestConsecutive(nums: number[]): number {
    const st = new Set(nums);
    let ans = 0;
    for (const num of st) {
        if (!st.has(num - 1)) {
            let curNum = num;
            let curScore = 1;
            while (st.has(curNum + 1)) {
                curNum++;
                curScore++;
            }
            ans = Math.max(ans, curScore);
        }
    }
    return ans;
}