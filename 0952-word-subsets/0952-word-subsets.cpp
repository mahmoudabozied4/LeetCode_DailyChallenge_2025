class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxCharFrequencies[26] = {0};
        int currentWordFrequencies[26];
        for (const auto& wordB : words2) {
            memset(currentWordFrequencies, 0, sizeof(currentWordFrequencies));
            for (const char& ch : wordB) {
                currentWordFrequencies[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCharFrequencies[i] =
                    std::max(maxCharFrequencies[i], currentWordFrequencies[i]);
            }
        }
        vector<string> universalWords;
        for (const auto& wordA : words1) {
            memset(currentWordFrequencies, 0, sizeof(currentWordFrequencies));
            for (const char& ch : wordA) {
                currentWordFrequencies[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (maxCharFrequencies[i] > currentWordFrequencies[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(wordA);
            }
        }
        return universalWords;
    }
};
