class Solution {
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations) {
        unordered_map<int, int> mp1;
        map<int, int> mp2;
        
        for (int num: nums) {
            mp1[num]++;
            mp2[num];
            mp2[num - k]++;
            mp2[num + k + 1]--;
        }


        int maxResult = 0, activeCount = 0;
        for (const auto &[position, delta]: mp2) {
            activeCount += delta;
            maxResult = max(maxResult, min(activeCount, mp1[position] + numOperations));
        }


        return maxResult;
    }
};
