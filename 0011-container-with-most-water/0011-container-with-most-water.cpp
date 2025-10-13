class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaFound = 0;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        while (leftIndex < rightIndex) {
            int currentArea = min(height[leftIndex], height[rightIndex]) *
                              (rightIndex - leftIndex);
            maxAreaFound = max(maxAreaFound, currentArea);
            if (height[leftIndex] < height[rightIndex]) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }
        return maxAreaFound;
    }
};