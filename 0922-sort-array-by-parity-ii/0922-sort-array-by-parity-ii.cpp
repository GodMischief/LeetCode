class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n);
        
        int evenIndex = 0;
        int oddIndex = 1;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }
        
        return result;
    }
};
