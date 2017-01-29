public class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int target = nums[(int)Math.ceil(nums.length / 2)];
        int result = 0;
        for (int num : nums) {
            result += Math.abs(target - num);
        }
        return result;
    }
}
