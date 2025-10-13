func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	var ans string = strs[0]
	for i := 1; i < len(strs); i++ {
		current_word := strs[i]
		for len(ans) > 0 && (len(current_word) < len(ans) || current_word[0:len(ans)] != ans) {
			ans = ans[:len(ans)-1]
		}
		if ans == "" {
			break
		}
	}
	return ans
}