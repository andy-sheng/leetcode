public class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int result = 0, tmp = 0;
        for (int num: nums) {
            if (num == 1) ++tmp;
            else {
                if (tmp > result) result = tmp;
                tmp = 0;
            }
        }
        return result > tmp ? result : tmp;
    }
}
