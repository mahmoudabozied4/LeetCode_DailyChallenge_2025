class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        unordered_map<int, long long> min_prefix;
        long long max_sum = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;

            if (min_prefix.count(mod)) {
                long long candidate = prefix[i] - min_prefix[mod];
                max_sum = max(max_sum, candidate);
            }

            if (!min_prefix.count(mod))
                min_prefix[mod] = prefix[i];
            else
                min_prefix[mod] = min(min_prefix[mod], prefix[i]);
        }

        return max_sum;
    }
};