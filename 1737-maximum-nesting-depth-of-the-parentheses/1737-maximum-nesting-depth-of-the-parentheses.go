func maxDepth(s string) int {
	maxNestingDepth := 0
	currentDepth := 0
	for _, ch := range s {
		switch ch {
		case '(':
			currentDepth++
			if currentDepth > maxNestingDepth {
				maxNestingDepth = currentDepth
			}
		case ')':
			currentDepth--
		}
	}

	return maxNestingDepth
}