public class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] tmp = new int[target + 1];
        tmp[0] = 1;
        for (int i = 1; i < tmp.length; i++) {
            int count = 0;
            for (int num : nums) {
                if (i - num >= 0) {
                    count += tmp[i - num];
                }
            }
            tmp[i] = count;
        }
        return tmp[target];
    }
}