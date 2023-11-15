class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end()); // Sort the array in ascending order

        arr[0] = 1; // Ensure the first element is 1

        for (int i = 1; i < arr.size(); ++i) {
            // Ensure the absolute difference between adjacent elements is less than or equal to 1
            arr[i] = std::min(arr[i], arr[i - 1] + 1);
        }

        return arr.back(); // Return the maximum element
    }
};