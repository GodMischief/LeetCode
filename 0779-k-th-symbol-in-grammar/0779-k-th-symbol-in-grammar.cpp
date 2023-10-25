class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: When n is 1, the first row is just "0".
        if (n == 1) {
            return 0;
        }
        
        // Calculate the length of the (n-1)th row.
        int len = 1 << (n - 2);
        
        // If k is in the first half of the (n-1)th row, it maps to the same value as the (n-1)th row.
        if (k <= len) {
            return kthGrammar(n - 1, k);
        } 
        // If k is in the second half, it is complemented to the (n-1)th row.
        else {
            return 1 - kthGrammar(n - 1, k - len);
        }
    }
};
