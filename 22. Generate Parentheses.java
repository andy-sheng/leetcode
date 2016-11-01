public class Solution {
    private int n;
    private int totalDep;
    private String tmp;
    private List<String> result = new ArrayList<>();
    private int k = 0;
    
    private void dfs(String tmp, int left, int right,int k, int dep) {
        if (left > this.n || right > this.n || k < 0) return;
        if (this.totalDep == dep) {
            this.result.add(tmp);
        } else {
            dfs(tmp + "(", left + 1, right,     k + 1, dep + 1);
            dfs(tmp + ")", left,     right + 1, k - 1, dep + 1);
        }
    }
    
    public List<String> generateParenthesis(int n) {
        this.n = n;
        this.totalDep = 2*n;
        this.dfs("", 0, 0, 0, 0);
        return this.result;
    }
}