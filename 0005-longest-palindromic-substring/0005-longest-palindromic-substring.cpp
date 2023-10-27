class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s; // If the string has 1 or 0 characters, it's already a palindrome.

        // Initialize a 2D DP table to store whether substrings are palindromes.
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int start = 0;  // Start index of the longest palindromic substring found so far.
        int maxLen = 1; // Length of the longest palindromic substring found so far.

        // All substrings of length 1 are palindromes.
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for substrings of length 3 or more.
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
