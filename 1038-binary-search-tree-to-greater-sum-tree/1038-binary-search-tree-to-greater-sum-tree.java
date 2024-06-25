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
    public TreeNode bstToGst(TreeNode root) {
        makeGst(root, 0);
        return root;
    }

    public int makeGst(TreeNode node, int headVal) {
        if(node.right != null)
            node.val += makeGst(node.right, headVal);
        else
            node.val += headVal;
        if(node.left != null)
            return makeGst(node.left, node.val);
        return node.val;
    }
}