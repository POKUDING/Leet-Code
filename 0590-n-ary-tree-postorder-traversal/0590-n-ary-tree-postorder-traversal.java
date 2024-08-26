/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> postorder(Node root) {
        if(root == null)
            return new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        solve(root, list);
        return list;
    }

    public void solve(Node node, List<Integer> list) {
        for(Node child : node.children)
            solve(child, list);
        list.add(node.val);
    }
}