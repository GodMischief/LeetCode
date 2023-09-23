class Solution {
public:
    int longestStrChain(std::vector<std::string>& words) {
        // Sort the words by length to ensure that we process shorter words before longer ones
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        });

        // Create an unordered map to store the length of the longest word chain ending at each word
        std::unordered_map<std::string, int> dp;

        // Initialize the maximum chain length to 1
        int maxChainLength = 1;

        // Iterate through each word in the sorted list
        for (const std::string& word : words) {
            // Initialize the chain length for this word to 1
            dp[word] = 1;

            // Try removing each character from the word to find predecessors
            for (int i = 0; i < word.size(); ++i) {
                std::string predecessor = word.substr(0, i) + word.substr(i + 1);

                // If the predecessor is in our unordered map, update the chain length
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = std::max(dp[word], dp[predecessor] + 1);
                }
            }

            // Update the maximum chain length
            maxChainLength = std::max(maxChainLength, dp[word]);
        }

        return maxChainLength;
    }
};