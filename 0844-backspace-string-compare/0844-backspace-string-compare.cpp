class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int sBackspaceCount = 0;
        int tBackspaceCount = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (s[i] == '#' || sBackspaceCount > 0)) {
                if (s[i] == '#') {
                    sBackspaceCount++;
                } else {
                    sBackspaceCount--;
                }
                i--;
            }
            
            while (j >= 0 && (t[j] == '#' || tBackspaceCount > 0)) {
                if (t[j] == '#') {
                    tBackspaceCount++;
                } else {
                    tBackspaceCount--;
                }
                j--;
            }
            
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else if (i >= 0 || j >= 0) {
                return false;
            }
            
            i--;
            j--;
        }
        
        return true;
    }
};
