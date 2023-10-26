class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        long long totalTrees = 0;

        for (int num : arr) {
            dp[num] = 1;  // Initialize as a single-node tree
            for (int factor : arr) {
                if (num % factor == 0) {
                    int complement = num / factor;
                    if (dp.count(complement)) {
                        dp[num] += dp[factor] * dp[complement];
                        dp[num] %= MOD;
                    }
                }
            }
            totalTrees += dp[num];
            totalTrees %= MOD;
        }

        return static_cast<int>(totalTrees);
    }
};
