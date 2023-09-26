class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);

        // Count the remainders after dividing each element by k.
        for (const int a : arr) {
            int remainder = (a % k + k) % k; // Handle negative numbers
            remainderCount[remainder]++;
        }

        // Check if remainders can be paired to form sums divisible by k.
        if (remainderCount[0] % 2 != 0) return false; // Handle remainder 0 separately
        for (int i = 1; i < k; ++i) {
            if (remainderCount[i] != remainderCount[k - i]) return false;
        }

        return true;
    }
};
