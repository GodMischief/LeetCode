class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_occurrence(26, -1); // Store the last occurrence of each character
        vector<bool> in_stack(26, false);    // Keep track of characters in the stack
        stack<char> char_stack;              // Stack to store the result

        // Step 1: Find the last occurrence of each character in the string
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        // Step 2: Process each character in the string
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (in_stack[c - 'a']) {
                continue; // Skip characters already in the stack
            }

            // Remove characters from the stack that are greater than the current character
            while (!char_stack.empty() && c < char_stack.top() && i < last_occurrence[char_stack.top() - 'a']) {
                in_stack[char_stack.top() - 'a'] = false;
                char_stack.pop();
            }

            char_stack.push(c);     // Add the current character to the stack
            in_stack[c - 'a'] = true;
        }

        // Step 3: Construct the result string from the stack
        string result = "";
        while (!char_stack.empty()) {
            result = char_stack.top() + result; // Build the result string in reverse order
            char_stack.pop();
        }

        return result;
    }
};
