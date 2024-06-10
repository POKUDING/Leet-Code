class Solution {
    public int heightChecker(int[] heights) {
        int cnt = 0;
        int[] sortedHeights = new int[heights.length];
        for(int i = 0; i < heights.length; ++i)
            sortedHeights[i] = heights[i];
        Arrays.sort(sortedHeights);

        for(int i = 0; i < heights.length; ++i)
            if(sortedHeights[i] != heights[i])
                ++cnt;
        return cnt;
    }
}