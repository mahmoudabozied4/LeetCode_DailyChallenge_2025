public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] index = new int[128];
        Arrays.fill(index, -1);
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (index[s.charAt(right)] >= left) {
                left = index[s.charAt(right)] + 1;
            }
            index[s.charAt(right)] = right;
            maxLen = Math.max(maxLen, right - left + 1);
        }  
        return maxLen;
    }

}