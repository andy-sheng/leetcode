public class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        for (; i > -1; i--) {
            for (; j > -1; j--) {
                if (t.charAt(j) == s.charAt(i)) {
                    break;
                }
            }
            if (j == -1) {
                return false;
            }
            j--;
        }
        return true;
    }
}
