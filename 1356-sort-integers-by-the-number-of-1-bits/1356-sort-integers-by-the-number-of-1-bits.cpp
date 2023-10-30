class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a); // Count 1 bits in a
            int countB = __builtin_popcount(b); // Count 1 bits in b

            if (countA == countB) {
                return a < b;
            }
            return countA < countB; // Sort by the number of 1's
        });

        return arr;
    }
};
