class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        int n = min(arrLen, (steps / 2) + 1);

        vector<vector<long>> dp(steps + 1, vector<long>(n, 0));
        dp[0][0] = 1;

        for (int step = 1; step <= steps; ++step) {
            for (int position = 0; position < n; ++position) {
                dp[step][position] = dp[step - 1][position];
                if (position > 0) dp[step][position] = (dp[step][position] + dp[step - 1][position - 1]) % MOD;
                if (position < n - 1) dp[step][position] = (dp[step][position] + dp[step - 1][position + 1]) % MOD;
            }
        }

        return dp[steps][0];
    }
};
