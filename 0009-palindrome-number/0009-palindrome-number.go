package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 || (x%10 == 0 && x != 0) {
		return false
	}

	var rev int = 0
	for x > rev {
		last_digit := x % 10
		rev = rev*10 + last_digit
		x /= 10
	}
	return x == rev || x == rev/10
}