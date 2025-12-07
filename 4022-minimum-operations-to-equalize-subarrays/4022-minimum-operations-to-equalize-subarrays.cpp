class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        
        vector<int> rem(nums.size());
        vector<long long> a(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            rem[i] = nums[i] % k;
            a[i] = nums[i] / k;
        }

        vector<int> diff(nums.size()), pref(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = (rem[i] != rem[i - 1]);
            pref[i] = pref[i - 1] + diff[i];
        }

        vector<long long> ans(queries.size());

        struct Query {
            int l;
            int r;
            int idx;
        };

        vector<Query> qq;

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == r) {
                ans[i] = 0;
                continue;
            }
            if (pref[r] - pref[l] > 0) {
                ans[i] = -1;
                continue;
            }
            qq.push_back({l, r, i});
        }

        if (qq.empty()) return ans;

        vector<long long> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int M = vals.size();

        vector<int> id(nums.size());
        for (int i = 0; i < nums.size(); i++)
            id[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();


        int block = max(1, (int) sqrt(nums.size()));

        sort(qq.begin(), qq.end(), [&](auto &a, auto &b) {
            int ba = a.l / block;
            int bb = b.l / block;
            if (ba != bb) return ba < bb;
            return (ba & 1) ? (a.r > b.r) : (a.r < b.r);
        });


        vector<int> bitCnt(M + 1, 0);


        auto add = [&](int i, int val) {
            for (++i; i <= M; i += i & -i)
                bitCnt[i - 1] += val;
        };

        auto get = [&](int i) {
            int res = 0;
            for (++i; i; i -= i & -i)
                res += bitCnt[i - 1];
            return res;
        };

        auto range = [&](int l, int r) {
            return get(r) - get(l - 1);
        };

        auto lb = [&](long long t) {
            int s = 0;
            int bitMask = 1;
            while ((bitMask << 1) <= M)
                bitMask <<= 1;

            for (int sz = bitMask; sz; sz >>= 1) {
                int nxt = s + sz;
                if (nxt <= M && bitCnt[nxt - 1] < t) {
                    t -= bitCnt[nxt - 1];
                    s = nxt;
                }
            }
            return s;
        };

        vector<long long> sm(M + 1, 0);

        auto addSm = [&](int i, long long val) {
            for (++i; i <= M; i += i & -i)
                sm[i - 1] += val;
        };

        auto getSm = [&](int i) {
            long long res = 0;
            for (++i; i; i -= i & -i)
                res += sm[i - 1];
            return res;
        };

        auto rangeSm = [&](int l, int r) {
            return getSm(r) - getSm(l - 1);
        };

        long long n = 0, totalSum = 0;
        int curL = 0, curR = -1;

        auto addPos = [&](int pos) {
            int cid = id[pos];
            add(cid, 1);
            addSm(cid, a[pos]);
            n++;
            totalSum += a[pos];
        };

        auto rmPos = [&](int pos) {
            int cid = id[pos];
            add(cid, -1);
            addSm(cid, -a[pos]);
            n--;
            totalSum -= a[pos];
        };

        auto getCost = [&]() {
            long long kth = (n + 1) / 2;
            int midIdx = lb(kth);
            long long med = vals[midIdx];

            long long leftCnt = range(0, midIdx);
            long long leftSum = rangeSm(0, midIdx);
            long long rightCnt = n - leftCnt;
            long long rightSum = totalSum - leftSum;

            return med * leftCnt - leftSum + rightSum - med * rightCnt;
        };

        for (auto &it: qq) {
            int L = it.l, R = it.r;

            while (curL > L) addPos(--curL);
            while (curR < R) addPos(++curR);
            while (curL < L) rmPos(curL++);
            while (curR > R) rmPos(curR--);

            ans[it.idx] = getCost();
        }

        return ans;
    }
};