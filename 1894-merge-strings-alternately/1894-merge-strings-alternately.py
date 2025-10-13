class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word1Idx = 0
        word2Idx = 0
        ans = ""
        while word1Idx < len(word1) and word2Idx < len(word2):
            ans += word1[word1Idx]
            word1Idx += 1
            ans += word2[word2Idx]
            word2Idx += 1
        if word1Idx <  len(word1):
            ans += word1[word1Idx:]

        if word2Idx < len(word2):
            ans += word2[word2Idx:]
            
        return ans