class Solution {
public:
    int countElements(vector<int> &nums, int k) {
        if (k == 0) return nums.size();
        sort(nums.begin(), nums.end());

        long long ans = 0;
        int i = 0;
        while (i < nums.size()) {
            int j = i;
            while (j < nums.size() && nums[j] == nums[i]) j++;
            int greaterCount = nums.size() - j;
            if (greaterCount >= k) ans += j - i;
            i = j;
        }
        return ans;
    }
};