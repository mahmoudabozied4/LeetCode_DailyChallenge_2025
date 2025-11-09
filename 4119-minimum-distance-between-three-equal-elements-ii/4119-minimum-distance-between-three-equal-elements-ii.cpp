class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> seen;

        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if ((seen[nums[i]].size()) < 2) {
                seen[nums[i]].push_back(i);
            } else {
                ans = min(ans, 2 * (i - seen[nums[i]][0]));
                seen[nums[i]][0] = seen[nums[i]][1];
                seen[nums[i]][1] = i;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};