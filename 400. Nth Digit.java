public class Solution {
    public int findNthDigit(int n) {
        int i = 1, tmp = n;
        while (i < 10 && n > 0) {
            tmp = n;
            n -= 9 * (int)Math.pow(10, i - 1) * i;
            ++i;
        }
        i--;
        int index = i - (tmp - 1) % i;
        int num = (int)Math.ceil((double)tmp / i) + (int)Math.pow(10, i - 1) - 1;
        return num % (int)Math.pow(10, index) / (int)Math.pow(10, index - 1);
    }
}
