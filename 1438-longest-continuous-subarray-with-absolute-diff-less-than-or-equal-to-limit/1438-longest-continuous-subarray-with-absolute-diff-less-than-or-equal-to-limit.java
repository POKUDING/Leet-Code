class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> decQ = new ArrayDeque<>();
        Deque<Integer> incQ = new ArrayDeque<>();
        int ans = 0;
        int left = 0;

        for (int right = 0; right < nums.length; ++right) {
            int num = nums[right];

            while (!decQ.isEmpty() && num > decQ.peekLast()) {
                decQ.pollLast();
            }
            decQ.addLast(num);

            while (!incQ.isEmpty() && num < incQ.peekLast()) {
                incQ.pollLast();
            }
            incQ.addLast(num);
            // System.out.println(decQ.toString() + " " + incQ.toString());

            while (decQ.peekFirst() - incQ.peekFirst() > limit) {
                if (decQ.peekFirst() == nums[left]) {
                    decQ.pollFirst();
                }
                if (incQ.peekFirst() == nums[left]) {
                    incQ.pollFirst();
                }
                ++left;
            }

            ans = Math.max(ans, right - left + 1);
        }

        return ans;
    }
}