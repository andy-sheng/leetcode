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
    public int rob(TreeNode root) {
        if (root == null) return 0;
        this.rob(root.left);
        this.rob(root.right);
        int robRoot = root.val;
        if (root.left != null) {
            if (root.left.left != null) {
                robRoot += root.left.left.val;
            }
            if (root.left.right != null) {
                robRoot += root.left.right.val;
            }
        }
        if (root.right != null) {
            if (root.right.left != null) {
                robRoot += root.right.left.val;
            }
            if (root.right.right != null) {
                robRoot += root.right.right.val;
            }
        }
        
        int notRobRoot = 0;
        if (root.left != null) {
            notRobRoot += root.left.val;
        }
        if (root.right != null) {
            notRobRoot += root.right.val;
        }
        root.val = (robRoot > notRobRoot) ? robRoot : notRobRoot;
        return root.val;
    }
}