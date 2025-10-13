
func maxArea(height []int) int {
	leftIndex := 0
	rightIndex := len(height) - 1
	maxWater := 0

	for leftIndex < rightIndex {
		currentWidth := rightIndex - leftIndex
		currentHeight := 0

		if height[leftIndex] < height[rightIndex] {
			currentHeight = height[leftIndex]
		} else {
			currentHeight = height[rightIndex]
		}

		currentWater := currentWidth * currentHeight

		if currentWater > maxWater {
			maxWater = currentWater
		}
		if height[leftIndex] < height[rightIndex] {
			leftIndex++
		} else {
			rightIndex--
		}
	}
	return maxWater
}