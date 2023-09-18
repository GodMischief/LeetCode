class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Find the iterator pointing to the first occurrence of target (or the insertion point).
        auto leftIt = lower_bound(nums.begin(), nums.end(), target);
        
        // Find the iterator pointing to the first element greater than target.
        auto rightIt = upper_bound(nums.begin(), nums.end(), target);
        
        // If leftIt and rightIt are the same, it means there are no occurrences of target.
        if (leftIt == rightIt) {
            return {-1, -1}; // Return {-1, -1} to indicate no occurrences found.
        }
        
        // Calculate the index of the leftmost occurrence.
        int left = leftIt - nums.begin();
        
        // Calculate the index of the rightmost occurrence by subtracting 1.
        int right = rightIt - nums.begin() - 1;
        
        // Return a vector containing the leftmost and rightmost indices.
        return {left, right};
    }
};
