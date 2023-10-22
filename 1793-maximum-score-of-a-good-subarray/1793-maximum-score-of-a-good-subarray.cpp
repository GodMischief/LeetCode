class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n);
        
        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            while (left[i] >= 0 && nums[left[i]] >= nums[i]) {
                left[i] = left[left[i]];
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            right[i] = i + 1;
            while (right[i] < n && nums[right[i]] >= nums[i]) {
                right[i] = right[right[i]];
            }
        }
        
        int maxScore = 0;
        
        for (int i = 0; i < n; i++) {
            if (left[i] < k && k < right[i]) {
                maxScore = max(maxScore, nums[i] * (right[i] - left[i] - 1));
            }
        }
        
        return maxScore;
    }
};
