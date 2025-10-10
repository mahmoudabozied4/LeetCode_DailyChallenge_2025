class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reverted_second_half = 0
        remaining_first_half = x

        while remaining_first_half > reverted_second_half:
            last_digit = remaining_first_half % 10
            reverted_second_half = reverted_second_half * 10 + last_digit
            remaining_first_half //= 10
        return remaining_first_half == reverted_second_half or remaining_first_half == reverted_second_half // 10
