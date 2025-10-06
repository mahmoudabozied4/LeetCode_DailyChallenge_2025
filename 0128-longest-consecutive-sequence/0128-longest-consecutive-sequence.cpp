class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        map<long long, long long> mp;
        int n = a.size();

        sort(a.begin(), a.end());
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            if (i == 0)
                mp[a[i]] = 1;
            else
                mp[a[i]] = max(1LL, mp[a[i] - 1] + 1);
            ans = max(ans, mp[a[i]]);
        }
        return ans;
    }
};