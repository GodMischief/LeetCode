class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 1; i <= n; ++i) {
            ans[i] = countOnes(i);
        }

        return ans;
    }

private:
    int countOnes(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
};
