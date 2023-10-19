class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return finalString(s) == finalString(t);
    }
    
private:
    string finalString(string s) {
        string result;
        for (char c : s) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
