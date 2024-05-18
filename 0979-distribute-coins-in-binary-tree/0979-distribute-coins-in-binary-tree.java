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
    private int moves;
    public int distributeCoins(TreeNode root) {
        moves = 0;
        checkMoves(root);
        // System.out.println(moves);
        return moves;
    }
    public int checkMoves(TreeNode node) {
        if(node == null)
            return 0;
        int leftMove = checkMoves(node.left);
        int rightMove = checkMoves(node.right);
        moves += Math.abs(leftMove) + Math.abs(rightMove);
        // System.out.println(leftMove + " " + rightMove + " " + moves);
        node.val += leftMove + rightMove;
        return node.val - 1;
    }
}