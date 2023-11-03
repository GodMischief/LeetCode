class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int targetPtr = 0; // Pointer for the target array
        int num = 1;      // Current number from the stream

        while (targetPtr < target.size()) {
            if (target[targetPtr] == num) {
                // If the current number matches the target, push and move to the next target
                result.push_back("Push");
                targetPtr++;
            } else {
                // If the current number doesn't match the target, push and pop
                result.push_back("Push");
                result.push_back("Pop");
            }
            num++;

            // Stop if we've reached the end of the target array
            if (targetPtr == target.size())
                break;
        }

        return result;
    }
};
