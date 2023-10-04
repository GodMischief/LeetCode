class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generatePermutations(nums, 0, result);
        return result;
    }
    
private:
    void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        // Generate permutations by swapping elements starting from the 'start' index
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            // Recursively generate permutations for the remaining elements
            generatePermutations(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
// Code by ~ Md Sohag Biswas
};


