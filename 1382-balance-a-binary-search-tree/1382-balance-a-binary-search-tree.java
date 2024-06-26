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
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();

        makeList(root, list);
        // System.out.println(list);
        return makeBST(list, 0, list.size() - 1);
    }

    public void makeList(TreeNode node, List<Integer> list) {
        if(node == null)
            return;
        makeList(node.left, list);
        list.add(node.val);
        makeList(node.right, list);
    }

    public TreeNode makeBST(List<Integer> list, int s, int e) {
        if(s > e)
            return null;
        int mid = (s + e) / 2;
        TreeNode node = new TreeNode(list.get(mid));
        node.left = makeBST(list, s, mid - 1);
        node.right = makeBST(list, mid + 1, e);
        return node;
    }
}