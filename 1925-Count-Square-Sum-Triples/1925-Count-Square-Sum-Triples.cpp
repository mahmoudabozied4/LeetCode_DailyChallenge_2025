class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a < n; a++) {
            for (int b = 1; b < n; ++b) {
                int sm = a * a + b * b;
                int sq = sqrt(sm);
                if (sq <= n and sq * sq == sm)
                    ans++;
            }
        }
        return ans;
    }
};
