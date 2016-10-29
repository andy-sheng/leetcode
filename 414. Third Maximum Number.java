public class Solution {
    public int thirdMax(int[] nums) {
        int[] maxs = new int[3];
        maxs[0] = nums[0];
        int pos = 1;
        for (int i = 1; i < nums.length && pos < 3; i++) {
            boolean flag = true;
            for (int j = 0; j < pos; j++) {
                if (nums[i] == maxs[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                maxs[pos++] = nums[i];
            }
        }
        if (pos == 1) return maxs[0];
        if (pos == 2) return maxs[0] > maxs[1] ? maxs[0] : maxs[1];
        
        Arrays.sort(maxs);
        for (int i = 3; i < nums.length; i++) {
            if (nums[i] > maxs[0]) {
                if (nums[i] > maxs[1]) {
                    if (nums[i] > maxs[2]) {
                        maxs[0] = maxs[1];
                        maxs[1] = maxs[2];
                        maxs[2] = nums[i];
                    } else if (nums[i] < maxs[2]){
                        maxs[0] = maxs[1];
                        maxs[1] = nums[i];
                    }
                } else if(nums[i] < maxs[1]) {
                    maxs[0] = nums[i];
                }
            }
        }
        return maxs[0];
    }
}