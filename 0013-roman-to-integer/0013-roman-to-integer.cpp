class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = romanValues[s.back()];
        for (int i = 0; i < s.size() - 1; ++i) {
            int sign = romanValues[s[i]] < romanValues[s[i + 1]] ? -1 : 1;
            result += sign * romanValues[s[i]];
        }
        return result;
    }
};