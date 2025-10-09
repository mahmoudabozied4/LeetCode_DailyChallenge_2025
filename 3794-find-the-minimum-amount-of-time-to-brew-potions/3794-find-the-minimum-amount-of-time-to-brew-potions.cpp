class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();

        long long finish[5005];
        finish[0] = skill[0] * mana[0];
        for (int i = 1; i < n; i++) {
            finish[i] = skill[i] * mana[0] + finish[i - 1];
        }

        for (int i = 1; i < m; i++) {
            long long start = -1;
            for (int j = 0; j < n; j++) {
                start = max(start, finish[j]) + skill[j] * mana[i];
            }
            for (int j = n - 1; j >= 0; j--) {
                finish[j] = start;
                start -= skill[j] * mana[i];
            }
        }

        return finish[n - 1];
    }
};