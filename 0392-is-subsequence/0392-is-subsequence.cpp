class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;
        for (char c : t) {
            if (s[sIndex] == c) {
                sIndex++;
            }
            if (sIndex == s.length()) {
                return true; // All characters in s are found in t
            }
        }
        return sIndex == s.length();
    }
};
