class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res ^= s[i];
            res ^= t[i];
        }
        res ^= t[s.size()];
        return res;
    }
};