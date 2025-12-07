class Solution {
public:
    int maxDistinct(string s) {
        vector < bool >  seen(26);
        int ans = 0;
        for (char c: s) {
            int idx = c - 'a';
            if (!seen[idx]) {
                seen[idx] = true;
                ++ans;
            }
        }
        return ans;
    }
};