class Solution {
public:
    static const int MOD = 1e9 + 7;

    int rearrangeSticks(int n, int k) {
        vector<long long> dp(k + 1, 0), new_dp(k + 1, 0);

        dp[0] = 1; 

        for (int i = 1; i <= n; i++) {
            for (int j = min(i, k); j >= 1; j--) {
                new_dp[j] = (dp[j - 1] + (long long)(i - 1) * dp[j]) % MOD;
            }
            new_dp[0] = 0;
            dp = new_dp;
        }

        return dp[k];
    }
};
