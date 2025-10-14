class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime;
        function<void(int)> Sieve = [&](int n) {
            prime.assign(n + 1, true);
            prime[0] = prime[1] = false;

            for (int i = 2; 1LL * i * i <= n; ++i) {
                if (!prime[i])
                    continue;
                for (int j = 2; 1LL * j * i <= n; ++j)
                    prime[1LL * i * j] = false;
            }
        };
        Sieve(n) ; 
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (prime[i])
                ans++;
        }
        return ans;
    }
};