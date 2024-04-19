class Solution {
    int[] dirX = {0, 1, 0, -1};
    int[] dirY = {1, 0, -1, 0};
    public int numIslands(char[][] grid) {
        int ans = 0;
        for(int y = 0; y < grid.length; ++y) {
            for(int x = 0; x < grid[y].length; ++x)
                if(grid[y][x] == '1')
                    ans += bfs(grid, y, x);
        }
        return ans;
    }

    public int bfs(char[][] grid, int y, int x) {
        Deque<int[]> que = new ArrayDeque<>();

        grid[y][x] = 2;
        que.push(new int[]{y, x});
        while(!que.isEmpty()) {
            int[] curr = que.poll();
            for(int i = 0; i < 4; ++i) {
                int nextY = curr[0] + dirY[i];
                int nextX = curr[1] + dirX[i];
                if(nextX < 0 || nextY < 0 || nextX >= grid[0].length || nextY >= grid.length || grid[nextY][nextX] != '1')
                    continue;
                grid[nextY][nextX] = '2';
                que.add(new int[] {nextY, nextX});
            }
        }
        return 1;
    }
}