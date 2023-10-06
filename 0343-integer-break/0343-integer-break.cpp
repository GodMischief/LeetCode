class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        vector<int> dp(n + 1);
        dp[2] = 2;
        dp[3] = 3;
        
        for (int i = 4; i <= n; ++i) {
            dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
        }
        
        return dp[n];
    }
};
