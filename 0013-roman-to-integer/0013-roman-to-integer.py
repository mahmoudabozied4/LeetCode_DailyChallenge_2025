class Solution:
    def romanToInt(self, s: str) -> int:
        roman_values = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        integer_value = 0
        prv = 0
        for i in range(len(s)):
            cur = roman_values[s[i]]
            if cur > prv and i > 0:
                integer_value += cur - 2 * prv
            else:
                integer_value += cur
            prv = cur
        return integer_value
