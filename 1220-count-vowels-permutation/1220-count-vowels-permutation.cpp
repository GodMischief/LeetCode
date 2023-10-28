class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1000000007;
        
        // Create a 2D DP array to store counts
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        
        // Initialize counts for strings of length 1
        for (int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }
        
        // Iterate through the lengths from 2 to n
        for (int length = 2; length <= n; length++) {
            dp[length][0] = (dp[length - 1][1] + dp[length - 1][2] + dp[length - 1][4]) % MOD;
            dp[length][1] = (dp[length - 1][0] + dp[length - 1][2]) % MOD;
            dp[length][2] = (dp[length - 1][1] + dp[length - 1][3]) % MOD;
            dp[length][3] = dp[length - 1][2];
            dp[length][4] = (dp[length - 1][2] + dp[length - 1][3]) % MOD;
        }
        
        // Calculate the total count for strings of length n
        long long totalCount = 0;
        for (int i = 0; i < 5; i++) {
            totalCount = (totalCount + dp[n][i]) % MOD;
        }
        
        return static_cast<int>(totalCount);
    }
};
