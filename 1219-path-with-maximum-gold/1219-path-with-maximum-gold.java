class Solution {
    static int max;
    static int width;
    static int height;
    static int[] dir = {1,0,-1,0};
    public int getMaximumGold(int[][] grid) {
        max = 0;
        height = grid.length;
        width = grid[0].length;
        for(int y = 0; y < grid.length; ++y) {
            for(int x = 0; x < grid[0].length; ++x) {
                dfs(grid, y, x, grid[y][x], new int[height][width]);
            }
        }
        return max;
    }

    public void dfs(int[][] grid, int y, int x, int curr, int[][] visit) {
        visit[y][x] = 1;
        for(int next = 0; next < 4; ++next) {
            int next_y = y + dir[next];
            int next_x = x + dir[(next + 1) % 4];
            if(next_y < 0 || next_x < 0 || next_y >= height || next_x >= width
                || grid[next_y][next_x] == 0 || visit[next_y][next_x] == 1)
                continue ;
            dfs(grid, next_y, next_x, curr + grid[next_y][next_x], visit);
        }
        visit[y][x] = 0;
        max = Math.max(max, curr);
    }
}