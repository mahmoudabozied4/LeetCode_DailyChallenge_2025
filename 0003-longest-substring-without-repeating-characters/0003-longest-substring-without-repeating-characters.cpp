class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map < char , int > mp;
        int ans = s.size() ? 1 : 0 , left = 0 ;
        for (int right = 0; right < s.size(); ++right) {
            if (mp.count(s[right]) && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right ;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
