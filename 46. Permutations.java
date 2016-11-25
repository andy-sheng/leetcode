public class Solution {
    private boolean[] table;
   
   public  List<List<Integer>> cal(int[] nums, int dep) {
       List<List<Integer>> results = new ArrayList<List<Integer>>();
       if (dep == 1) {
           List<Integer> tmp = new ArrayList<>();
           for (int i = 0; i < nums.length; ++i) {
                if (!this.table[i]) {
                    tmp.add(nums[i]);
                    results.add(tmp);
                    break;
                }
           }
           return results;
       }
        for (int i = 0; i < nums.length; ++i) {
            if (this.table[i]) continue; // if this number has used
            this.table[i] = true;
            List<List<Integer>> subResults = this.cal(nums, dep - 1);
            this.table[i] = false;
            for(List<Integer> subResult: subResults) {
                subResult.add(0, nums[i]);
                results.add(subResult);
            }
        }
        return results;
   }
    public List<List<Integer>> permute(int[] nums) {
        this.table = new boolean[nums.length];
        for(int i = 0; i < nums.length; ++i) {
            this.table[i] = false;
        }
    
        return this.cal(nums, nums.length);
    }
}
