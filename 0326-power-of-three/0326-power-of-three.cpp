class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0 ) return false;
        long long  cur = 1; 
        while(cur <= n){
            if(cur == n) return true ;
            cur*=3;
        }
        return false ; 
    }
};