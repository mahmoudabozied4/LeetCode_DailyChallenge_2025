class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        long long sum = 0;
        
        const int INF = 1e9;
        int min1_r1 = INF, min2_r1 = INF;
        int min1_r2 = INF, min2_r2 = INF;

        for (int x : nums) {
            sum += x;
            int r = x % 3;

            if (r == 1) {
                if (x < min1_r1) {
                    min2_r1 = min1_r1;
                    min1_r1 = x;
                } else if (x < min2_r1) {
                    min2_r1 = x;
                }
            } 
            else if (r == 2) {
                if (x < min1_r2) {
                    min2_r2 = min1_r2;
                    min1_r2 = x;
                } else if (x < min2_r2) {
                    min2_r2 = x;
                }
            }
        }

        int mod = sum % 3;
        if (mod == 0) return sum;

        long long removeCost = LLONG_MAX;

        if (mod == 1) {
            if (min1_r1 < INF) removeCost = min(removeCost, (long long)min1_r1);
            if (min1_r2 < INF && min2_r2 < INF) 
                removeCost = min(removeCost, (long long)min1_r2 + min2_r2);
        } else { // mod == 2
            if (min1_r2 < INF) removeCost = min(removeCost, (long long)min1_r2);
            if (min1_r1 < INF && min2_r1 < INF) 
                removeCost = min(removeCost, (long long)min1_r1 + min2_r1);
        }

        if (removeCost == LLONG_MAX) return 0;
        return sum - removeCost;
    }
};
