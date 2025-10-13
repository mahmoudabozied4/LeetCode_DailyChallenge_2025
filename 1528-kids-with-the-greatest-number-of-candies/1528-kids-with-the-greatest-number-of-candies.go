package main

import "fmt"

func kidsWithCandies(candies []int, extraCandies int) []bool {
	ans := make([]bool, len(candies))
	mx := 0
	for _, candy := range candies {
		mx = max(mx, candy)
	}
	for i, it := range candies {
		if it+extraCandies >= mx {
			ans[i] = true
		}
	}
	return ans
}