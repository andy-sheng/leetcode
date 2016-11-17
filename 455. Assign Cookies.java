public class Solution {
    public int findContentChildren(int[] g, int[] s) {
         int result = 0;
         Arrays.sort(g);
         Arrays.sort(s);
         int j = 0;
         for (int i = 0; i < g.length && j < s.length; ++i) {
             for (; j < s.length; ++j) {
                 if (g[i] <= s[j]) {
                     ++j;
                     ++result;
                     break;
                 }
             }
         }
         return result;
    }
}
