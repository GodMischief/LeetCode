class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            int left = n, right = -1;

            for (int i = 0; i < n; ++i) {
                if (s[i] == ch) {
                    left = min(left, i);
                    right = max(right, i);
                }
            }

            if (left < right) {
                unordered_set<char> unique_chars;
                for (int i = left + 1; i < right; ++i) {
                    unique_chars.insert(s[i]);
                }
                result += unique_chars.size();
            }
        }

        return result;
    }
};