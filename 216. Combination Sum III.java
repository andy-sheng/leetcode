public class Solution {
    private List<List<Integer>>find(int k, int n, int start) {
        List<List<Integer>> result = new ArrayList<>();
        if (k == 0 ) return result;
        for (int i = start; i < 10; ++i) {
            if (n - i == 0 && k == 1) {
                List<Integer> tmp = new ArrayList<>();
                tmp.add(i);
                result.add(tmp);
                return result;
            }
            if (n - i > i) {
                List<List<Integer>> tmps = find(k - 1, n - i, i + 1);
                for (List<Integer> tmp:tmps) {
                    tmp.add(0, i);
                    result.add(tmp);
                }
            }
        }
        return result;
    }
    
    public List<List<Integer>> combinationSum3(int k, int n) {
         return this.find(k, n, 1);
    }
}
