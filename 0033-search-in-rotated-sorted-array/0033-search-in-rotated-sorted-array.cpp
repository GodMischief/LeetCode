class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;               // Initialize the left pointer to the start of the array.
    int right = nums.size() - 1; // Initialize the right pointer to the end of the array.

    while (left <= right) { // Continue the loop as long as left is less than or equal to right.
      int mid = left + (right - left) / 2; // Calculate the middle index using a safe formula to avoid overflow.

      if (nums[mid] == target) { // If the middle element is equal to the target, we've found the target.
        return mid; // Return the index where the target is found.
      }

      if (nums[left] <= nums[mid]) { // If the left half is sorted.
        if (nums[left] <= target && target < nums[mid]) { // If the target is in the left sorted half.
          right = mid - 1; // Adjust the right pointer to search in the left half.
        } else { // Otherwise, search in the right half.
          left = mid + 1; // Adjust the left pointer to search in the right half.
        }
      } else { // If the right half is sorted.
        if (nums[mid] < target && target <= nums[right]) { // If the target is in the right sorted half.
          left = mid + 1; // Adjust the left pointer to search in the right half.
        } else { // Otherwise, search in the left half.
          right = mid - 1; // Adjust the right pointer to search in the left half.
        }
      }
    }

    return -1; // If the target is not found in the array, return -1.
  }
};
