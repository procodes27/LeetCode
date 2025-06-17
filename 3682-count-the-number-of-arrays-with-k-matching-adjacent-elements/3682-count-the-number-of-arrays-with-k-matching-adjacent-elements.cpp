int MOD = 1e9 + 7;

class Solution {
public:
    long long findPower(long long a, long long b) {
        long long result = 1;
        a %= MOD;
        while (b > 0) {
            if (b % 2 == 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return result;
    }

    long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact) {
        return ((factorial[n] * fermatFact[n - r]) % MOD * fermatFact[r]) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }

        vector<long long> fermatFact(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(factorial[i], MOD - 2);
        }

        long long result = nCr(n - 1, k, factorial, fermatFact);
        result = result * m % MOD;
        result = result * findPower(m - 1, n - k - 1) % MOD;

        return result;
    }
};
