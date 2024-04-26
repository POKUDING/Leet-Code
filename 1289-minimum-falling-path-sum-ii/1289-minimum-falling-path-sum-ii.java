class Solution {
    public int minFallingPathSum(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int Max = Integer.MAX_VALUE;
        int prevMin = 0, prevSecondMin = 0, prevMinIdx = 0;
        int currMin = 0, currSecondMin = 0, currMinIdx = 0;

        for(int row = 0; row < height; ++row) {
            prevMin = currMin;
            prevSecondMin = currSecondMin;
            prevMinIdx = currMinIdx;
            currMin = Max;
            currSecondMin = Max;
            for(int col = 0; col < width; ++col) {
                // System.out.println(grid[row][col] + " " + col + " " + prevMinIdx + " " +prevSecondMin + " " + prevMin);
                grid[row][col] += (col == prevMinIdx ? prevSecondMin : prevMin);
                // System.out.println(grid[row][col]);
                if(grid[row][col] < currMin) {
                    currSecondMin = currMin;
                    currMin = grid[row][col];
                    currMinIdx = col;
                } else if(grid[row][col] < currSecondMin) {
                    currSecondMin = grid[row][col];
                }
            }
        }
        for(int col = 0; col < width; ++col) {
            Max = Math.min(Max, grid[height - 1][col]);
        }
        return Max;
    }
}