class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false; 
        }
        
        stack<int> stk; 
        int third = INT_MIN; // Initialize the third element as the minimum possible value.
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true; // If we find a '1' element that is less than 'third', we found a 132 pattern.
            }
            
            while (!stk.empty() && nums[i] > stk.top()) {
                third = stk.top(); // Update 'third' with the top element of the stack.
                stk.pop();
            }
            
            stk.push(nums[i]); // Push the current element onto the stack.
        }
        
        return false; 
    }
};
