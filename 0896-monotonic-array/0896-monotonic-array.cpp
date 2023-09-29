class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;   // Initialize a flag for increasing order
        bool decreasing = true;   // Initialize a flag for decreasing order

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false; 
            } else if (nums[i] < nums[i - 1]) {
                increasing = false; 
            }
        }

        return increasing || decreasing;
    }
//Code by ~ Md Sohag Biswas
};
