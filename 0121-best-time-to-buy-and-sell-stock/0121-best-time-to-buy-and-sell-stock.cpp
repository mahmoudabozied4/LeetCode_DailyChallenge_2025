class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int least_price = prices[0];
        int ans = 0;

        for (int cur_price : prices) {

            int ret = cur_price - least_price;
            ans = max(ans, ret);

            least_price = min(cur_price, least_price);
        }

        return ans;
    }
};