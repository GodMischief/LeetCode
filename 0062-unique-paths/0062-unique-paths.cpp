class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (m == 1 || n == 1) return 1;

    vector<int> dp(n, 1);

    for (int i = 1; i < m; ++i) {
      int prev = 1; // Initialize prev to 1 for the first column
      for (int j = 1; j < n; ++j) {
        dp[j] = dp[j] + prev;
        prev = dp[j];
      }
    }

    return dp[n - 1];
  }
//Code by ~ Md Sohag Biswas
};
