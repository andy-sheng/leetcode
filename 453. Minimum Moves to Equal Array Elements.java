public class Solution {
    public int minMoves(int[] nums) {
        int min = nums[0];
        for (int num:nums) {
            if (num < min) {
                min = num;
            }
        }
        
        int result = 0;
        for (int num:nums) {
            result += num - min;
        }
        return result;
    }
}
