class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int m = s.length();
        for (int i = 0; i < m; i++) {
            if (s[i] == ' ') {
                if (i + 1 < m && s[i + 1] != ' ') {
                    length = 0;
                }
            } else {
                length++;
            }
        }
        return length;
    }
};