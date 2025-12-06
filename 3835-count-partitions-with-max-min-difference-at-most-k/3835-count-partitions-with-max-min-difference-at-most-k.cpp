class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        multiset<long long> window;

        vector<long long> dp(n + 1, 0);
        vector<long long> prefix(n + 1, 0);

        dp[0] = 1;
        prefix[0] = 1;

        int L = 1;
        for (int R = 1; R <= n; R++) {
            long long x = nums[R - 1];
            window.insert(x);

            while (!window.empty() && *window.rbegin() - *window.begin() > k) {
                window.erase(window.find(nums[L - 1]));
                L++;
            }

            long long prevSum = (L >= 2 ? prefix[L - 2] : 0);

            dp[R] = (prefix[R - 1] - prevSum + MOD) % MOD;
            prefix[R] = (prefix[R - 1] + dp[R]) % MOD;
        }

        return dp[n];
    }
};