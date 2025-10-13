package main

import "fmt"

func gcd(a int, b int) int {
	if b != 0 {
		return gcd(b, a%b)
	}
	return a
}
func gcdOfStrings(str1 string, str2 string) string {
	str1PlusStr2 := str1 + str2
	str2PlusStr1 := str2 + str1
	if str2PlusStr1 != str1PlusStr2 {
		return ""
	}
	str1Len := len(str1)
	str2Len := len(str2)

	g := gcd(str1Len, str2Len)

	return str1[0:g]
}
