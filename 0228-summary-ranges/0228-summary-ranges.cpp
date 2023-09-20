class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> ans;

        int start = 0;
        int end = 0;

        while (end < nums.size()) {
            while (end + 1 < nums.size() && nums[end] == nums[end + 1] - 1) {
                ++end;
            }

            if (start == end) {
                ans.push_back(std::to_string(nums[start]));
            } else {
                ans.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[end]));
            }

            start = end + 1;
            end = start;
        }

        return ans;
    }
};