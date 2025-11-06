class Solution {
public:
    struct DSU {
        vector<int> parent, rankv;
        DSU(int n) {
            parent.resize(n + 1);
            rankv.assign(n + 1, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb)
                return;
            if (rankv[ra] < rankv[rb])
                swap(ra, rb);
            parent[rb] = ra;
            if (rankv[ra] == rankv[rb])
                rankv[ra]++;
        }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto& e : connections)
            dsu.unite(e[0], e[1]);

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
            heaps;
        for (int i = 1; i <= c; ++i) {
            int r = dsu.find(i);
            heaps[r].push(i);
        }

        vector<bool> online(c + 1, true);
        vector<int> ans;

        auto getMinOnline = [&](int root) {
            auto& pq = heaps[root];
            while (!pq.empty() && !online[pq.top()])
                pq.pop(); // lazy deletion
            return pq.empty() ? -1 : pq.top();
        };

        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);
            if (type == 1) {
                if (online[x])
                    ans.push_back(x);
                else
                    ans.push_back(getMinOnline(root));
            } else {               // type == 2
                online[x] = false; // no need to remove immediately
            }
        }

        return ans;
    }
};