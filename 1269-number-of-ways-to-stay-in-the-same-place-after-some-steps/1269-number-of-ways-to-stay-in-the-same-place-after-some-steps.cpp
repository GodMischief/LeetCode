class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        int n = min(arrLen, (steps / 2) + 1);
        vector<long> dp(n, 0);
        dp[0] = 1;

        for (int step = 0; step < steps; ++step) {
            vector<long> newDp(n, 0);

            for (int i = 0; i < n; ++i) {
                newDp[i] = dp[i];
                if (i > 0) newDp[i] = (newDp[i] + dp[i - 1]) % MOD;
                if (i < n - 1) newDp[i] = (newDp[i] + dp[i + 1]) % MOD;
            }

            dp = move(newDp);
        }

        return dp[0];
    }
};
