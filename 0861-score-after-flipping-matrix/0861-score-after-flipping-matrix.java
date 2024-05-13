class Solution {
    public int matrixScore(int[][] grid) {
        int height = grid.length;
        int width = grid[0].length;
        int maxScore = (1 << width - 1) * height;

        for(int x = 1; x < width; ++x) {
            int countEquals = 0;

            for(int y = 0; y < height; ++y)
                if(grid[y][x] == grid[y][0])
                    ++countEquals;
            maxScore += Math.max(countEquals, height - countEquals) * (1 << (width - x - 1));
        }
        return maxScore;
    }
}