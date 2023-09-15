class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSquared = nums[left] * nums[left];
            int rightSquared = nums[right] * nums[right];

            if (leftSquared > rightSquared) {
                ans[index--] = leftSquared;
                left++;
            } else {
                ans[index--] = rightSquared;
                right--;
            }
        }

        return ans;
    }
};
