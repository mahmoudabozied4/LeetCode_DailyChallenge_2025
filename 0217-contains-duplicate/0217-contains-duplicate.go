
func containsDuplicate(numbers []int) bool {
	seenNumbers := make(map[int]bool)

	for _, number := range numbers {
		// Check if the number has already been seen
		if seenNumbers[number] {
			return true
		}

		// If the number is not in seenNumbers, add it.
		seenNumbers[number] = true

	}

	// If no duplicates were found, return false
	return false
}