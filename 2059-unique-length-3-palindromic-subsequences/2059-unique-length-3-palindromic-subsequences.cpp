class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int> l(26, s.size()), r(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            const int index = s[i] - 'a';
            l[index] = min(l[index], i);
            r[index] = i;
        }
        for (int i = 0; i < 26; ++i) {
            if (l[i] < r[i])
                ans += unordered_set<int>(s.begin() + l[i] + 1, s.begin() + r[i]).size();
        }
        return ans;
    }
};
