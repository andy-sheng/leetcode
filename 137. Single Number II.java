public class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        int []tmp = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int num: nums) {
            int pos = 1;
            for (int i = 0; i < 32; ++i) {
                tmp[i] += (num & pos) == 0 ? 0 : 1;
                pos = pos << 1;
            }
        }
        int pos = 1;
        for (int posCount:tmp) {
            result += (posCount%3) == 1 ? pos : 0;
            pos = pos << 1;
        }
        return result;
    }
}
