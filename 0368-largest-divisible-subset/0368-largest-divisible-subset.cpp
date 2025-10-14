class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // dp[i] = size of largest subset ending at nums[i]
        // prev[i] = index of previous element in subset
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        

        int max_size = 1;
        int max_idx = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    
                    if (dp[i] > max_size) {
                        max_size = dp[i];
                        max_idx = i;
                    }
                }
            }
        }
        
        vector<int> result;
        while (max_idx != -1) {
            result.push_back(nums[max_idx]);
            max_idx = prev[max_idx];
        }
        
        return result;
    }
};