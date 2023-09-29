class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int left = 0;
        int right = arr.size() - k; 
        
        while (left < right) {
            int mid = left + (right - left) / 2; // Calculate the middle index

            // Check if the right half has closer elements to x
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1; // Move the left pointer to the right
            } else {
                right = mid; // Move the right pointer to the middle 
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
//Code by ~ Md Sohag Biswas
};
