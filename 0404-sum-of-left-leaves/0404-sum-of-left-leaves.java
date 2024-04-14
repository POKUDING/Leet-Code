/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static int ans;
    public void dfs(TreeNode curr, boolean left) {
        if(curr.left == null && curr.right == null && left == true)
            ans += curr.val;
        if(curr.left != null)
            dfs(curr.left, true);
        if(curr.right != null)
            dfs(curr.right, false);
    }

    public int sumOfLeftLeaves(TreeNode root) {
        ans = 0;
        dfs(root, false);
        return ans;
    }
}