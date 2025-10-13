package main

import "fmt"

func romanToInt(romanNumeral string) int {

	romanMap := map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	ans := 0

	for i := 0; i < len(romanNumeral); i++ {
		currentValue := romanMap[rune(romanNumeral[i])]

		if i+1 < len(romanNumeral) {
			nextValue := romanMap[rune(romanNumeral[i+1])]
			if currentValue < nextValue {
				ans -= currentValue
			} else {
				ans += currentValue
			}
		} else {
			ans += currentValue
		}
	}
	return ans
}