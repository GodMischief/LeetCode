class Solution {
public:
  char findTheDifference(string s, string t) {
    char ans = 0; // Initialize a variable 'ans' to store the result.

    // XOR operation with characters in string 's'.
    for (const char c : s)
      ans ^= c;

    // XOR operation with characters in string 't'.
    for (const char c : t)
      ans ^= c;

    return ans; // Return the final result.
  }
};
