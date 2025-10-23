class Solution:
    def maxDepth(self, s: str) -> int:
        max_nesting_depth = 0
        current_depth = 0
        for ch in s:
            if ch == "(":
                current_depth += 1
                max_nesting_depth = max(max_nesting_depth, current_depth)
            elif ch == ")":
                current_depth -= 1
        return max_nesting_depth
