class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next;
            for (int i = 0; i < s.length(); ++i) {
                int sum = 0;
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    sum += s[j] - '0';
                }
                next += to_string(sum);
                i += k - 1; // Skip the digits that have been summed
            }
            s = move(next);
        }
        return s;
    }
};