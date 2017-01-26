public class Solution {
    public boolean isPerfectSquare(int num) {
        int low = 1, high = 46340;
        while(low <= high) {
            int mid = (low + high) / 2;
            int tmp = mid * mid;
            if (tmp > num) {
                high = mid - 1;
            } else if(tmp < num) {
                low = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
