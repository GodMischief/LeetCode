class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Check if the array has less than 2 elements, return true
        if (arr.size() <= 2) {
            return true;
        }

        // Sort the array
        sort(arr.begin(), arr.end());

        // Calculate the common difference
        int commonDiff = arr[1] - arr[0];

        // Check if the difference between all consecutive elements is the same
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != commonDiff) {
                return false;
            }
        }

        return true;
    }
};
