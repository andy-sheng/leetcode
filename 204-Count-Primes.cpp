class Solution {
public:
    vector<int> prime;
    bool inited = false;
    bool isPrime(int n) {
        int m = sqrt(n);
        int primeLength = prime.size();
        for (int i = 0; i < primeLength && prime[i] <= m; i++) {
            if (n % prime[i] == 0) return false;
        }
        if (prime[primeLength - 1] < m) {
            for (int i = prime[primeLength - 1]; i < m; i++) {
                if (n % i == 0) return false;
            }
        }
        if (prime[primeLength - 1] < n) {
            prime.push_back(n);
        }
        return true;
    }
    int countPrimes(int n) {
        if (!inited) {
           prime.push_back(2);

         inited = true;
        }
        if (n == 0) return 0;
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) result++;
        }
        return result;
    }
};
