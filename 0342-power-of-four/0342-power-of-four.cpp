class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false; 
        }
        
        if ((n & (n - 1)) != 0) {
            return false;
        }
        return (int)log2(n) % 2 == 0;
    }
};
