class Solution {
public:
    long long countTrapezoids(vector<vector<int> > &points) {
        struct hash {
            size_t operator()(const pair<int,int> &p) const noexcept {
                return (static_cast<uint64_t>(static_cast<uint32_t>(p.first)) << 32) ^ static_cast<uint32_t>(p.second);
            }
        };

        int n = points.size();

        auto norm_line = [&](int x1, int y1, int x2, int y2) -> pair<pair<int, int>, long long> {
            int dx = x2 - x1;
            int dy = y2 - y1;
            if (dx == 0) {
                pair<int,int> slope = {1, 0};
                long long line_id = x1;
                return {slope, line_id};
            }
            int g = std::gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            int a = dy, b = dx;
            long long c = 1LL * b * y1 - 1LL * a * x1;
            return {{a, b}, c};
        };

        unordered_map<pair<int,int>, unordered_map<long long,int>, hash> cnt1;
        unordered_map<pair<int,int>, unordered_map<pair<int,int>,int, hash>, hash> cnt2;

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < i; ++j) {
                int x2 = points[j][0], y2 = points[j][1];

                auto [slope, line_id] = norm_line(x1, y1, x2, y2);
                cnt1[slope][line_id]++;

                pair<int,int> mid = {x1 + x2, y1 + y2};
                cnt2[mid][slope]++;
            }
        }

        long long ans = 0;

        for (auto [_ , lines]: cnt1) {
            long long s = 0;
            for (auto &[_, c]: lines) {
                ans += s * c;
                s += c;
            }
        }

        for (auto &[_ , slopes]: cnt2) {
            long long s = 0;
            for (auto [_ , c]: slopes) {
                ans -= s * c;
                s += c;
            }
        }

        return ans;
    }
};