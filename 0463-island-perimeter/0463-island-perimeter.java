class Solution {
    static int[] dirX = {0, 1 ,0, -1};
    static int[] dirY = {1, 0, -1, 0};
    public int islandPerimeter(int[][] grid) {
        int[] start = findFirstLand(grid);
        return bfs(grid, start);
    }

    public int[] findFirstLand(int[][] grid) {
        for(int y = 0; y < grid.length; ++y) {
            for(int x = 0; x < grid[y].length; ++x)
                if(grid[y][x] == 1)
                    return new int[]{y, x};
        }
        return new int[]{0,0};
    }

    public int bfs(int[][] grid, int[] start) {
        int ans = 0;
        int[][] visit = new int[grid.length][grid[0].length];
        Deque<int[]> que = new ArrayDeque<> ();

        que.add(start);
        visit[start[0]][start[1]] = 1;
        while(!que.isEmpty()) {
            int[] curr = que.poll();
            ans += checkLength(grid, curr[0], curr[1]);
            for(int i = 0; i < 4; ++i) {
                int nextY = curr[0] + dirY[i];
                int nextX = curr[1] + dirX[i];
                if(nextX <0 || nextY < 0 || nextY >= grid.length || nextX >= grid[0].length)
                    continue;
                if(grid[nextY][nextX] == 0 || visit[nextY][nextX] == 1)
                    continue;
                visit[nextY][nextX] = 1;
                que.add(new int[]{nextY, nextX});
            }
        }
        return ans;
    }

    public int checkLength(int[][] grid, int y, int x) {
        int length = 0;
        for(int i = 0; i < 4; ++i) {
            int currY = y + dirY[i];
            int currX = x + dirX[i];
            if(currY >= 0 && currX >= 0 && currY < grid.length && currX < grid[0].length
                && grid[currY][currX] == 1)
                continue;
            ++length;
        }
        // System.out.println("y: " + y +",x: " + x + ",length: " + length);
        return length;
    }
}