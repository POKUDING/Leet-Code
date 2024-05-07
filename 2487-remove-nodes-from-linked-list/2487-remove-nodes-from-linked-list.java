class Solution {
    public ListNode removeNodes(ListNode head) {
        Deque<ListNode> stack = new ArrayDeque<>();
        ListNode curr = head;
        while(curr != null) {
            while(!stack.isEmpty() && stack.peekLast().val < curr.val)
                stack.pollLast();
            stack.add(curr);
            curr = curr.next;
        }
        head = null;
        while(!stack.isEmpty()) {
            curr = stack.pollLast();
            curr.next = head;
            head = curr;
        }
        return head;
    }
}