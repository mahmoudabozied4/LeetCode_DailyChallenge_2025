package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	charMap := make(map[byte]int) // < char , int >
	left := 0
	ans := 0
	for right := 0; right < len(s); right++ {
		char := s[right]
		if lastIndex, ok := charMap[char]; ok && lastIndex >= left {
			left = lastIndex + 1
		}
		charMap[char] = right

		ans = max(ans, right-left+1)
	}
	return ans
}