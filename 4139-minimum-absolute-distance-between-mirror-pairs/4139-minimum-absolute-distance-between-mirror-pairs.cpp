class Solution {
public:
    int minMirrorPairDistance(vector<int> &nums) {
        unordered_map<int, int> lastIdx;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            auto it = lastIdx.find(val);
            if (it != lastIdx.end()) {
                int prevIndex = it->second;
                ans = min(ans, i - prevIndex);
            }
            long long rev = 0;
            while (val > 0) {
                rev = rev * 10 + (val % 10);
                val /= 10;
            }
            lastIdx[rev] = i;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
