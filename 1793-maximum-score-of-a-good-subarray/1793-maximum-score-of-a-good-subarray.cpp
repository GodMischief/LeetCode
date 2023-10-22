class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> leftStack, rightStack;
        
        // Find the first smaller element to the left of each element
        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() && nums[i] <= nums[leftStack.top()]) {
                leftStack.pop();
            }
            left[i] = (leftStack.empty() ? -1 : leftStack.top());
            leftStack.push(i);
        }
        
        // Find the first smaller element to the right of each element
        for (int i = n - 1; i >= 0; i--) {
            while (!rightStack.empty() && nums[i] <= nums[rightStack.top()]) {
                rightStack.pop();
            }
            right[i] = (rightStack.empty() ? n : rightStack.top());
            rightStack.push(i);
        }
        
        int maxScore = 0;
        
        // Calculate the maximum score for each element
        for (int i = 0; i < n; i++) {
            if (left[i] < k && k < right[i]) {
                maxScore = max(maxScore, nums[i] * (right[i] - left[i] - 1));
            }
        }
        
        return maxScore;
    }
};
