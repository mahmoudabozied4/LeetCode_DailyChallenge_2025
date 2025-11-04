class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        unordered_map<int, int> freq;
        map<pair<int, int>, int> freqMap; // (frequency, value)

        auto add = [&](int val) {
            int f = freq[val]++;
            if (f > 0)
                freqMap.erase({f, val});
            freqMap[{f + 1, val}]++;
        };

        auto remove = [&](int val) {
            int f = freq[val]--;
            freqMap.erase({f, val});
            if (f - 1 > 0)
                freqMap[{f - 1, val}]++;
            if (freq[val] == 0)
                freq.erase(val);
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= k)
                remove(nums[i - k]);
            if (i >= k - 1) {
                long long sum = 0;
                int cnt = 0;
                for (auto it = freqMap.rbegin();
                     it != freqMap.rend() && cnt < x; ++it) {
                    int f = it->first.first;
                    int val = it->first.second;
                    sum += 1LL * f * val;
                    cnt++;
                }
                result.push_back(sum);
            }
        }
        return result;
    }
};