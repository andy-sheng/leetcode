public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList();
        for(int i = nums.length - 1; i > -1; --i) {
            nums[(nums[i] - 1)% nums.length] += nums.length;
        }
        for (int i = nums.length - 1; i > -1; --i) {
            if (nums[i] <= nums.length) {
                result.add(i+1);
            }
        }
        return result;
    }
}
