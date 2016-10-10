public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int result = 10;
        int tmp = 9;
        for(int i = 1; i < n; i++) {
            tmp *= 10 - i;
            result += tmp;
        }
        return result;
    }
}
