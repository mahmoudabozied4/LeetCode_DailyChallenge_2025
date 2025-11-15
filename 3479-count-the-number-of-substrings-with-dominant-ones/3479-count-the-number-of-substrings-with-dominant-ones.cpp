class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i + i * i <= s.size(); ++i) {
            int lst = -1;
            vector<int> a(2);
            for (int l = 0, r = 0; r < s.size(); ++r) {
                ++a[s[r] - '0'];
                for (; l < r; ++l)
                    if (s[l] == '0' && a[0] > i)
                        --a[0], lst = l;
                    else if (s[l] == '1' && a[1] - 1 >= i * i)
                        --a[1];
                    else
                        break;

                if (a[0] == i && a[1] >= i * i)
                    ans += l - lst;
            }
        }
        return ans;
    }
};
