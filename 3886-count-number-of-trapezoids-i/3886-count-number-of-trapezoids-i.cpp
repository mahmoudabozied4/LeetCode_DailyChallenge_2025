class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        long long MOD = 1e9 + 7;
        unordered_map<long long, long long> mp;
        for (const auto& p : points) ++mp[p[1]];
    
        long long ans = 0, res = 0;
        for (const auto& [_, c] : mp) {
            long long curr = (c * (c - 1) / 2) % MOD;
            ans = (ans + (res * curr) % MOD) % MOD;
            res = (res + curr) % MOD;
        }
        return ans;
    }
};