class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        vector<int> zied = nums;
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] = (nums[i] == target ? 1 : -1);

        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + a[i - 1];

        auto all = pref;
        
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        auto getId = [&](long long x) {
            return int(lower_bound(all.begin(), all.end(), x) - all.begin());
        };

        int N = all.size();
        vector<int> v(N), bit(N + 1);
        auto get = [&](int i) {
            int res = 0;
            for (++i; i; i -= (i & -i))
                res += bit[i - 1];
            return res;
        };
        auto set = [&](int i, int val) {
            for (++i; i <= N; i += (i & -i))
                bit[i - 1] = val;
        };

        auto add = [&](int i, int val) {
            for (++i; i <= N; i += (i & -i))
                bit[i - 1] += val;
        };
        auto getRange = [&](int s, int e) {
            return get(e) - (s ? get(s - 1) : 0);
        };
        auto getVal = [&](int i) {
            return getRange(i, i);
        };
        auto lb = [&](int t) {
            int s = 0;
            for (int sz = N >> 1; sz; sz >>= 1)
                if (bit[s + sz - 1] < t)
                    t -= bit[(s += sz) - 1];
            return s;
        };

        long long ans = 0;
        for (int j = 0; j <= n; ++j) {
            int id = getId(pref[j]);
            ans += get(id - 1); 
            add(id, 1);
        }
        return ans;
    }
};
