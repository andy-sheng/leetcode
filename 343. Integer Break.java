public class Solution {
    public int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        return (n % 3 == 1) ? (int)Math.pow(3, n / 3 - 1) * 4 : (n % 3 == 2) ? (int)Math.pow(3, n / 3) * 2 :  (int)Math.pow(3, n / 3);
    }
}
