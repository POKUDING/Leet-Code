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
    String ans;
    public String smallestFromLeaf(TreeNode root) {
        ans = new String();
        dfs(root, new String());
        return ans;
    }

    public void dfs(TreeNode node, String str) {
        str = ((char)(node.val + 'a')) + str;
        if(node.left == null && node.right == null && (ans.length() == 0 || ans.compareTo(str) > 0))
                ans = str;
        if(node.left != null)
            dfs(node.left, str);
        if(node.right != null)
            dfs(node.right, str);
    }
}