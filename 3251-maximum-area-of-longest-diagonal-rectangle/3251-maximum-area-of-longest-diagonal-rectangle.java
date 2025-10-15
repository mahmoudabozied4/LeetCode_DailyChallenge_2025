class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int mxArea = 0; 
        int mxDiagonal = 0;
        for (int[] dimension : dimensions) {
            int l = dimension[0], r = dimension[1];
            int cur = l * l + r * r;
            if (mxDiagonal < cur) {
                mxDiagonal = cur;
                mxArea = l * r;
            } else if (mxDiagonal == cur) {
                mxArea = Math.max(mxArea, l * r);
            }
        }
        return mxArea;
    }
}