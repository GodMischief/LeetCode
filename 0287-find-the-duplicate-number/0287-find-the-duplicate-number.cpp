class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<bool> seen(n, false);

        for (int num : nums) {
            if (seen[num]) {
                return num;
            }
            seen[num] = true;
        }

        return -1; // No duplicate found (optional)
    }
};
