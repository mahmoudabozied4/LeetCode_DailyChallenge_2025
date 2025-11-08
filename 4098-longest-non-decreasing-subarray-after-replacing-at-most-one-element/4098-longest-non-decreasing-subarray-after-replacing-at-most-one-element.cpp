class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return n;
        vector<int> dpEnd(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] <= nums[i])
                dpEnd[i] = dpEnd[i - 1] + 1;
            else
                dpEnd[i] = 1;
        }
        vector<int> dpStart(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1])
                dpStart[i] = dpStart[i + 1] + 1;
            else
                dpStart[i] = 1;
        }
        int ans = 1;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dpEnd[i]); // Dont Use +

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n)
                ans = max(ans, min(n, dpEnd[i] + 1));
            if (i - 1 >= 0)
                ans = max(ans, min(n, dpStart[i] + 1));
        }


        // connect Bridge
        for (int i = 0; i + 1 < n; ++i) {
            if (nums[i] <= nums[i + 1])
                continue;
            bool changeDp1 = (i == 0) || (nums[i - 1] <= nums[i + 1]);
            bool changeDp2 = (i + 1 == n - 1) || (nums[i] <= nums[i + 2]);
            if (changeDp1 || changeDp2) {
                int cur = dpEnd[i] + dpStart[i + 1];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};