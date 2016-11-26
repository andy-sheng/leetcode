public class Solution {
    private long helper(int start, int end) {
        long result = 1;
        for (int i = start; i <= end; i++) result *= i;
        //System.out.println(start+"---"+end+"----"+result);
        return result;
    }
    private int c(int m, int n) {
        //System.out.println("c:"+m+"---"+n);
        return (int)(this.helper(n - m + 1, n) / this.helper(1,m));
    }
    public int uniquePaths(int m, int n) {
        --m;
        --n;
        if (m == 0 || n == 0) return 1;
        return this.c(Math.min(n, m), m + n);
    }
}
