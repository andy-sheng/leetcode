/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int[] pathArray = new int[1000];
    private int[][] sums = new int[1000][1000];
    private int result = 0;
    private int sum = 0;
    
    private void travel(TreeNode root, int level) {
        if (root == null) return;
        this.pathArray[level] = root.val;
        this.sums[level][level] = root.val;
        if (root.val == this.sum) this.result++;
        for (int i = level - 1; i > -1; i--) {
            this.sums[i][level] = this.sums[i][level - 1] + root.val;
            if (this.sums[i][level] == this.sum) result++;
        }
        this.travel(root.left, level+1);
        this.travel(root.right, level+1);
    }
    
    public int pathSum(TreeNode root, int sum) {
        this.sum = sum;
        this.travel(root, 0);
        return this.result;
    }
    
}