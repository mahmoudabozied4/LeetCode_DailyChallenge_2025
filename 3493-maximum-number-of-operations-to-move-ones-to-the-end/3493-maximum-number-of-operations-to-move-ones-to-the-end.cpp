class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, ones = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++ones;
            else if (i + 1 == s.size() or s[i + 1] == '1')
                ans += ones;
        }
        return ans;
    }
}
;