class Solution {
    public int maxArea(int[] height) {
        int[][] heights = new int[height.length][2];
        PriorityQueue<Integer> pq1 = new PriorityQueue<>();
        PriorityQueue<Integer> pq2 = new PriorityQueue<>((i1,i2)->i2-i1);
        int curr = 0, arrIdx = 0;
        int max = 0, l = 0, r = 0;
        for(int i = 0; i < height.length; ++i){
            heights[i][0] = height[i];
            heights[i][1] = i + 1;
            curr = Math.max(curr, height[i]);
        }
        Arrays.sort(heights,(h1, h2)->h2[0] - h1[0]);

        while(curr > 0) {
            while(arrIdx < heights.length && heights[arrIdx][0] >= curr) {
                pq1.add(heights[arrIdx][1]);
                pq2.add(heights[arrIdx][1]);
                ++arrIdx;
            }
            l = pq1.peek();
            r = pq2.peek();
            max = Math.max(max, (r - l) * curr);
            --curr;
        }
        return max;
    }
}