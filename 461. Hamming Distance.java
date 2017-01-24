public class Solution {
    public int hammingDistance(int x, int y) {
        int result = 0;
        int tmp = x ^ y;
        while(tmp != 0) {
            result ++;
            tmp &= tmp - 1;
        }
        return result;
    }
}
