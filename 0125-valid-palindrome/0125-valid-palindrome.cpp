class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isAlphanumeric(s[left]))
                ++left;

            // Skip non-alphanumeric characters from the right
            while (left < right && !isAlphanumeric(s[right]))
                --right;

            // Compare characters ignoring case
            if (toLowerCase(s[left]) != toLowerCase(s[right]))
                return false;

            // Move to the next characters
            ++left;
            --right;
        }

        // If we reach here, it's a palindrome
        return true;
    }

private:
    bool isAlphanumeric(char c) {
        return isalpha(c) || isdigit(c);
    }

    char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        return c;
    }
};
