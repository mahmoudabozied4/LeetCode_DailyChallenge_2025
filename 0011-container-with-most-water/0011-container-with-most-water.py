class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_water = 0
        left_index = 0
        right_index = len(height) - 1
        
        while left_index < right_index:
            current_width = right_index - left_index
            current_height = min(height[left_index], height[right_index])
            current_water = current_width * current_height
            max_water = max(max_water, current_water)
            if height[left_index] < height[right_index]:
                left_index += 1
            else:
                right_index -= 1
        return max_water
