class Solution {
    public int islandPerimeter(int[][] grid) {
        int ans = 0;
        for(int y = 0; y < grid.length; ++y) {
            for(int x = 0; x < grid[0].length; ++x) {
                if(grid[y][x] == 1) {
                    ans += 4;
                    if(y > 0 && grid[y - 1][x] == 1)
                        ans -= 2;
                    if(x > 0 && grid[y][x - 1] == 1)
                        ans -= 2;
                }
            }
        }
        return ans;
    }
}