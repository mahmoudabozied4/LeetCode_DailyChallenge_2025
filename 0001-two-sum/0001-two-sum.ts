function twoSum(nums: number[], target: number): number[] {
    const mp = new Map()
    for (let i = 0; i < nums.length; i++) {
        if (mp.has(nums[i])) {
            return[ mp.get(nums[i]) , i]
        }
        mp.set(target - nums[i], i)
    }
    return [0 , 0]
};