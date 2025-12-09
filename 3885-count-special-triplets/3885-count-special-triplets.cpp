class Solution {
public:
    int specialTriplets(vector<int> &nums) {
        unordered_map<int, int> l, r;
        for (auto &it: nums) r[it]++;
        long long MOD = 1e9 + 7, result = 0;
        for (int it: nums) {
            r[it]--;
            int tar = it * 2;
            result = (result + 1LL * l[tar] * r[tar] % MOD) % MOD;
            l[it]++;
        }
        return int(result);
    }
};