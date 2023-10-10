class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int ans = n;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int j = 0; // Initialize a pointer to the start of the subsequence
        for (int i = 0; i < nums.size(); ++i) {
            const int end = nums[i] + n - 1;

            // Advance the pointer j to the first element greater than or equal to end
            while (j < nums.size() && nums[j] <= end) {
                j++;
            }

            const int uniqueLength = j - i;
            ans = min(ans, n - uniqueLength);
        }

        return ans;
    }
};
