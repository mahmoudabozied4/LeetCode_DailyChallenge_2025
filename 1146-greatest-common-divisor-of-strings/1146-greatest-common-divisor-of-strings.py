class Solution:
    def gcd(self , a , b):
        if b != 0:
            return self.gcd(b , a % b)
        return a
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2 != str2 + str1: return ""
        g= self.gcd(len(str1) , len(str2))
        return str1[:g]
