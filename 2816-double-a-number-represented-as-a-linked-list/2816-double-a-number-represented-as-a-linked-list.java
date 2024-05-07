/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode doubleIt(ListNode head) {
        Deque<Integer> stack = new ArrayDeque<>();
        while(head != null) {
            stack.add(head.val);
            head = head.next;
        }
        ListNode next = null;
        int prev = 0;
        while(!stack.isEmpty()) {
            int curr = stack.pollLast() * 2;
            curr += prev;
            next = new ListNode(curr % 10, next);
            prev = curr / 10;
        }
        if(prev != 0)
            next = new ListNode(prev, next);
        if (next == null)
            return new ListNode(0);
        return next;
    }
}