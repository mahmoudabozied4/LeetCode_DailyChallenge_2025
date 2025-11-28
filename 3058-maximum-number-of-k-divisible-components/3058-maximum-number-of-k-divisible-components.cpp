class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int> > adj(n, vector<int>());
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        long long total = 0;
        for (int v : values) total += v;

        if (total % k != 0) return 0;
        int components = 0;
        function<long long(int,int)> dfs = [&](int u, int parent) -> long long {
            long long cur = values[u] % k;
            for (int v : adj[u]) {
                if (v == parent) continue;
                cur += dfs(v, u);
                cur %= k;
            }

            if (cur % k == 0) {
                components++;
                return 0LL;
            }

            return cur;
        };

        auto _ = dfs(0, -1);
        return components;
    }
};