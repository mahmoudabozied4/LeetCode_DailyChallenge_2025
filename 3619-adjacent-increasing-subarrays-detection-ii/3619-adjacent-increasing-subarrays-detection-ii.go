func maxIncreasingSubarrays(nums []int) int {
	if len(nums) < 2 {
		return 0
	}
	ans := 0
	increasing := 1
	prevIncreasing := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			increasing++
		} else {
			prevIncreasing = increasing
			increasing = 1
		}
		ans = max(ans, increasing/2)
		ans = max(ans, min(prevIncreasing, increasing))
	}
	return ans
}