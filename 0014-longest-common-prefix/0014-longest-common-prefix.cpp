class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // If the input list is empty, return an empty string.
        }

        for (int i = 0; i < strs[0].length(); ++i) { // Loop through characters of the first string.
            for (int j = 1; j < strs.size(); ++j) { // Loop through all other strings.
                if (i == strs[j].length() || strs[j][i] != strs[0][i]) {
                    // If we reach the end of a string or find a character that doesn't match
                    // the corresponding character in the first string, return the common prefix
                    // up to this point.
                    return strs[0].substr(0, i);
                }
            }
        }

        // If we haven't found a mismatch, the entire first string is the common prefix.
        return strs[0];
    }
};
