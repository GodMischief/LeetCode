const int MOD = 1000000007;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        
        for (int j = 1; j <= m; ++j) {
            dp[1][j][1] = 1;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int cost = 1; cost <= k; ++cost) {
                    long long ways = 0;
                    for (int prev = 1; prev < j; ++prev) {
                        ways = (ways + dp[i - 1][prev][cost - 1]) % MOD;
                    }
                    ways = (ways + dp[i - 1][j][cost] * j) % MOD;
                    dp[i][j][cost] = ways;
                }
            }
        }
        
        long long totalWays = 0;
        for (int j = 1; j <= m; ++j) {
            totalWays = (totalWays + dp[n][j][k]) % MOD;
        }
        
        return static_cast<int>(totalWays);
    }
};
