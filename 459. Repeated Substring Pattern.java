public class Solution {
    public boolean repeatedSubstringPattern(String str) {
        char startChar = str.charAt(0);
        char endChar = str.charAt(str.length() - 1);
        int len = str.length() / 2;
        for (int i = 0; i < len; ++i) {
            if (str.charAt(i) != endChar || str.length() % (i + 1) != 0) continue; // find the possible subtring
            
            int j = 0;
            while (j < str.length() && str.charAt(j) == str.charAt(j % (i + 1))) {
                ++j;
            }
            if (j == str.length()) return true;
        }
        return false;
    }
}
