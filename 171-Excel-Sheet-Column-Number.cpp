class Solution {
public:
    int titleToNumber(string s) {
        int value = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int tmp = s[i] - 'A' + 1;
            value = value * 26 + tmp;
        }
        return value;
    }
    
};