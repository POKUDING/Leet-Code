class Solution {
    public int minFallingPathSum(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;

        for(int row = 1; row < height; ++row) {
            for(int col = 0; col < width; ++col) {
                int currNum = grid[row][col];
                grid[row][col] = Integer.MAX_VALUE;
                for(int prevCol = 0; prevCol < width; ++prevCol) {
                    if(prevCol == col) continue;
                    grid[row][col] = Math.min(grid[row][col], currNum + grid[row - 1][prevCol]);
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int col = 0; col < width; ++col) {
            ans = Math.min(ans, grid[height - 1][col]);
        }
        return ans;
    }
}