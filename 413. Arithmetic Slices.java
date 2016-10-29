public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int[] subA = new int[A.length];
        for (int i = A.length - 1; i > 0; i--) {
            subA[i] = A[i] - A[i - 1];
        }
        int result = 0;
        int count = 2;
        for (int i = 2; i < subA.length; i++) {
            if (subA[i] == subA[i - 1]) {
                count++;
                result += count - 2;
            } else {
                count = 2;
            }
        }
        return result;
    }
}