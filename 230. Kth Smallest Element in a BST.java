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
    private int k;
    private TreeNode travel(TreeNode root) {
        if (root == null) return null;
        TreeNode result = this.travel(root.left);
        if (result != null) return result;
        
        this.k--;
        if (this.k == 0) return root;
        
        result = this.travel(root.right);
        if (result != null) return result;
        return null;
    }
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        TreeNode result = this.travel(root);
        return result.val;
    }
}