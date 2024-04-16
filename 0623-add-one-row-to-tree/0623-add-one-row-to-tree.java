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
    static int newVal;
    static int targetDep;
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        newVal = val;
        targetDep = depth;
        if(depth == 1) {
            TreeNode newRoot = new TreeNode(newVal);
            newRoot.left = root;
            return newRoot;
        }
        dfs(root, 1);
        return root;
    }
    public void dfs(TreeNode node, int currDep) {
        if(currDep + 1 == targetDep) {
                TreeNode curr = node.left;
                node.left = new TreeNode(newVal);
                node.left.left = curr;
                TreeNode curr = node.right;
                node.right = new TreeNode(newVal);
                node.right.right = curr;
            return ;
        }
        if(node.left != null)
            dfs(node.left,currDep + 1);
        if(node.right != null)
            dfs(node.right,currDep + 1);
    }
}