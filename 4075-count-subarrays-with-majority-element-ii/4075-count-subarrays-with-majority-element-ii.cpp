class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
    struct coordinateCopmression {
    private:
        vector<long long> init;
        void compress(vector<long long>& v) {
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
        }
    public:
        coordinateCopmression(vector<long long>& v) {
            init = v;
            compress(init);
        }
        int index(long long val) {
            return int(lower_bound(init.begin(), init.end(), val) - init.begin());
        }
        long long initVal(int idx) {
            return init[idx];
        }
    };


    int n = nums.size();

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = (nums[i] == target ? +1 : -1);

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + a[i - 1];

    coordinateCopmression cc(pref);
    int N = (int)cc.index(*max_element(pref.begin(), pref.end())) + 1;

    vector<int> v(N), bit(N + 1);

    auto get = [&](int i) {
        int res = 0;
        for (++i; i; i -= (i & -i)) res += bit[i - 1];
        return res;
    };

    auto set = [&](int i, int val) {
        for (++i; i <= N; i += (i & -i)) bit[i - 1] = val;
    };

    auto add = [&](int i, int val) {
        for (++i; i <= N; i += (i & -i)) bit[i - 1] += val;
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
        int id = cc.index(pref[j]);
        ans += get(id - 1);
        add(id, 1);     
    }

    return ans;
    }
};