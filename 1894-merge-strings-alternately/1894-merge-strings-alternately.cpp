class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1_idx = 0 , word2_idx = 0;
        string ans;
        while (word1_idx < word1.size() && word2_idx < word2.size()) {
            ans.push_back(word1[word1_idx++]);
            ans.push_back(word2[word2_idx++]);
        }
        while (word1_idx < word1.size()) {
            ans.push_back(word1[word1_idx++]);
        }
        while (word2_idx < word2.size()) {
            ans.push_back(word2[word2_idx++]);
        }
        return ans;
    }
};
