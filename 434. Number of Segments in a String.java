public class Solution {
    public int countSegments(String s) {
        boolean letter = false;
        int result = 0;
        for (int i = s.length() - 1; i > -1; --i) {
            if (s.charAt(i) == ' ') letter = false;
            else {
                if (!letter) ++result;
                letter = true;
            }
        }
        return result;
    }
}
