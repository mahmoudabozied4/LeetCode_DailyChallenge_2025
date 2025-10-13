public class Solution {

    public int maxArea(int[] height) {
        int maxAreaFound = 0;
        int leftIndex = 0;
        int rightIndex = height.length - 1;

        while (leftIndex < rightIndex) {
            int currentWidth = rightIndex - leftIndex;
            int currentHeight = Math.min(height[leftIndex], height[rightIndex]);
            int currentArea = currentWidth * currentHeight;

            maxAreaFound = Math.max(maxAreaFound, currentArea);

            // Move the pointer of the shorter line.
            if (height[leftIndex] < height[rightIndex]) {

                // Moving left pointer for potentially larger height.
                leftIndex++;

            } else {

                // Moving the right pointer.
                rightIndex--;

            }
        }

        return maxAreaFound;
    }
}