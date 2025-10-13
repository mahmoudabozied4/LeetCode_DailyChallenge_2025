class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}
        for idx , num in enumerate(nums):
            need = target - nums[idx]
            if need in mp: return [mp[need], idx]
            mp[num] = idx

        return []