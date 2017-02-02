public class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            int pos = Math.abs(nums[i]) - 1;
            if (nums[pos] < 0) {
                res.add(pos + 1);
            } else {
                nums[pos] = 0 - nums[pos];    
            }
        }
        return res;
    }
}
