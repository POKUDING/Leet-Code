class Solution {
    public int trap(int[] height) {
        int rtn = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Map<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < height.length; ++i) {
            if(height[i] == 0) continue;
            int minHeight = 0;
            while(!pq.isEmpty() && pq.peek() <= height[i]) {
                int top = pq.remove();
                rtn += (i - map.get(top) - 1) * (top - minHeight);
                minHeight = top;
                // System.out.println(i + " " + rtn);
            }
            // System.out.println(pq.toString());
            // System.out.println(i + ": " + map.toString());
            if(!pq.isEmpty())
                rtn += (i - map.get(pq.peek()) - 1) * (height[i] - minHeight);
            pq.add(height[i]);
            map.put(height[i], i);
        }
        return rtn;
    }
}