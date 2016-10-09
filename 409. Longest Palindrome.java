public class Solution {
    public int longestPalindrome(String s) {
        int[] map = new int[60]{0};
        for(int i = 0; i < 60; i++) {
            map[i] = 0;
        }
        int result = 0;
        for(int i = s.length() - 1; i > -1; i--) {
            map[s.charAt(i) - 'A']++;
        }
        Boolean centerAvalible = true;
        for(int i = 0; i < 60; i++) {
            if (centerAvalible) {
                if (map[i] % 2 == 1) {
                    result += 1;
                    centerAvalible = false;
                }
            }
            if (map[i] > 0) {
                result += (map[i] % 2 == 1) ? map[i] - 1 : map[i];
            }
        }
        return result;
    }
}