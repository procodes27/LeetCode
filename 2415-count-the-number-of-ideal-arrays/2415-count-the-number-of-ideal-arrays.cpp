class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(15, vector<int>(maxValue + 1));
        for (int i = 1; i <= maxValue; ++i) dp[1][i] = 1;
        for (int len = 2; len < 15; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = 2 * i; j <= maxValue; j += i) {
                    dp[len][j] = (dp[len][j] + dp[len - 1][i]) % MOD;
                }
            }
        }
        vector<int> fact(n + 1), invFact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
        invFact[n] = power(fact[n], MOD - 2, MOD);
        for (int i = n - 1; i >= 0; --i) invFact[i] = 1LL * invFact[i + 1] * (i + 1) % MOD;

        auto comb = [&](int a, int b) -> int {
            if (a < b) return 0;
            return 1LL * fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
        };

        int res = 0;
        for (int len = 1; len < 15; ++len) {
            int sum = 0;
            for (int i = 1; i <= maxValue; ++i) {
                sum = (sum + dp[len][i]) % MOD;
            }
            res = (res + 1LL * sum * comb(n - 1, len - 1) % MOD) % MOD;
        }
        return res;
    }

    int power(int a, int b, int mod) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1LL * res * a % mod;
            a = 1LL * a * a % mod;
            b >>= 1;
        }
        return res;
    }
};
