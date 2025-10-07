class Solution {
public:
    static const int N = 200 * 200 + 5; 
    static int nxt[N][26];
    static int frq[N];
    int cntNode;

    int get(char ch) { return ch - 'a'; }

    void add(const string &s) {
        int node = 0;
        for (char ch : s) {
            int c = get(ch);
            if (nxt[node][c] == 0)
                nxt[node][c] = ++cntNode;
            node = nxt[node][c];
            frq[node]++;
        }
    }

    string buildLCP(int totalWords) {
        string prefix;
        int node = 0;
        while (true) {
            int childIndex = -1, childCount = 0;
            for (int i = 0; i < 26; ++i) {
                if (nxt[node][i]) {
                    childIndex = i;
                    childCount++;
                }
            }
            if (childCount != 1 || frq[nxt[node][childIndex]] != totalWords)
                break;
            node = nxt[node][childIndex];
            prefix.push_back('a' + childIndex);
        }
        return prefix;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        memset(nxt, 0, sizeof(nxt));
        memset(frq, 0, sizeof(frq));
        cntNode = 0;

        for (auto &s : strs) add(s);
        return buildLCP((int)strs.size());
    }
};
int Solution::nxt[Solution::N][26];
int Solution::frq[Solution::N];
