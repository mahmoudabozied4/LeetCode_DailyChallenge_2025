class Solution {
    long long LCM(long long a, long long b) {
        if (a > b) {
            long long old_a = a;
            for (; a % b; a += old_a);
            return a;
        } else {
            long long old_b = b;
            for (; b % a; b += old_b);
            return b;
        }
    }

    int GCD(int a, int b) {
        if (b)
            return GCD(b, a % b);
        else
            return a;
    }

public:
    string gcdOfStrings(string STR1, string STR2) {
        if (STR1 + STR2 != STR2 + STR1) {
            return "";
        }
        int greatestCommonDivisorLength = std::gcd(STR1.length(), STR2.length());
        return STR1.substr(0, greatestCommonDivisorLength);
    }
};