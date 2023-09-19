class Solution {
public:
  int climbStairs(int n) {
    std::stack<int> s;
    s.push(1); // dp[0]
    s.push(1); // dp[1]

    for (int i = 2; i <= n; ++i) {
      int prev1 = s.top();
      s.pop();
      int prev2 = s.top();
      s.pop();
      
      const int dp = prev1 + prev2;
      s.push(prev1); // push dp[i-1]
      s.push(dp);    // push dp[i]
    }

    return s.top();
  }
};
