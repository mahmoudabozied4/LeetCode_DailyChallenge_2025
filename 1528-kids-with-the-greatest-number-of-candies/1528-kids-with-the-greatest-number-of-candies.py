class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        mx = max(candies)
        ans =[]
        for it in candies:
            if(it + extraCandies >= mx): ans.append(True)
            else: ans.append(False)
        return ans