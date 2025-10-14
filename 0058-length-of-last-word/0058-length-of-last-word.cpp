class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag = false;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ' && !flag)
                continue;
            if (s[i] == ' ' && flag)
                break;
            if (s[i] != ' ') {
                flag = true;
                cnt++;
            }
        }
        return cnt ;
    }
};