package main

import "fmt"

func mergeAlternately(word1 string, word2 string) string {
	ans := ""
	word1Idx := 0
	word2Idx := 0

	for i := 0; i < min(len(word1), len(word2)); i++ {
		ans += string(word1[word1Idx])
		word1Idx++
		ans += string(word2[word2Idx])
		word2Idx++
	}

	for i := word1Idx; i < len(word1); i++ {
		ans += string(word1[i])
	}

	for i := word2Idx; i < len(word2); i++ {
		ans += string(word2[i])
	}
	return ans
}